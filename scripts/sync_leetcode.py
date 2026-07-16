#!/usr/bin/env python3
"""
sync_leetcode.py — Fetch all solved LeetCode problems and sync into the repo.

Uses LeetCode's GraphQL API to:
1. Fetch the list of all accepted submissions for a user
2. Fetch problem metadata (difficulty, tags, description)
3. Fetch accepted submission source code (requires LEETCODE_SESSION)
4. Create/update solution folders with metadata, README, and code files

Environment Variables:
  LEETCODE_SESSION  — Session cookie for authenticated requests (required for code)
  LEETCODE_USERNAME — Override default username (optional, defaults to ShyamTripathi12)
"""

import os
import sys
import json
import time
import re
import hashlib
from datetime import datetime, timezone

# ---------------------------------------------------------------------------
# Try to import requests — the only external dependency
# ---------------------------------------------------------------------------
try:
    import requests
except ImportError:
    print("[ERROR] 'requests' is required. Install with: pip install requests")
    sys.exit(1)

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_DIR = os.path.dirname(SCRIPT_DIR)
LEETCODE_DIR = os.path.join(REPO_DIR, "leetcode")
SYNC_STATE_PATH = os.path.join(SCRIPT_DIR, "sync_state.json")

LEETCODE_USERNAME = os.environ.get("LEETCODE_USERNAME", "ShyamTripathi12")
LEETCODE_SESSION = os.environ.get("LEETCODE_SESSION", "")
GRAPHQL_URL = "https://leetcode.com/graphql"

# Rate-limit delay between API requests (seconds)
REQUEST_DELAY = 0.6

# LeetCode language slug → file extension mapping
LANG_EXT_MAP = {
    "python":      ".py",
    "python3":     ".py",
    "cpp":         ".cpp",
    "c":           ".c",
    "java":        ".java",
    "javascript":  ".js",
    "typescript":  ".ts",
    "golang":      ".go",
    "rust":        ".rs",
    "ruby":        ".rb",
    "swift":       ".swift",
    "kotlin":      ".kt",
    "csharp":      ".cs",
    "scala":       ".scala",
    "php":         ".php",
    "dart":        ".dart",
}

# Normalise LeetCode lang slugs to canonical names for metadata.json
LANG_CANONICAL = {
    "python":     "python",
    "python3":    "python",
    "cpp":        "cpp",
    "c":          "c",
    "java":       "java",
    "javascript": "javascript",
    "typescript": "typescript",
    "golang":     "go",
    "rust":       "rust",
    "ruby":       "ruby",
    "swift":      "swift",
    "kotlin":     "kotlin",
    "csharp":     "csharp",
    "scala":      "scala",
    "php":        "php",
    "dart":       "dart",
}

# ---------------------------------------------------------------------------
# HTTP helpers
# ---------------------------------------------------------------------------

def _build_headers():
    """Build request headers, optionally with session cookie."""
    headers = {
        "Content-Type": "application/json",
        "Referer": f"https://leetcode.com/u/{LEETCODE_USERNAME}/",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
                      "(KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36",
        "Origin": "https://leetcode.com",
    }
    if LEETCODE_SESSION:
        headers["Cookie"] = f"LEETCODE_SESSION={LEETCODE_SESSION}"
    return headers


def graphql_request(query: str, variables: dict, operation: str = "") -> dict:
    """Send a GraphQL POST request to LeetCode. Returns the JSON response body."""
    payload = {"query": query, "variables": variables}
    if operation:
        payload["operationName"] = operation
    try:
        resp = requests.post(GRAPHQL_URL, json=payload, headers=_build_headers(), timeout=30)
        resp.raise_for_status()
        data = resp.json()
        if "errors" in data:
            print(f"  [WARN] GraphQL errors: {data['errors']}")
        return data.get("data", {})
    except requests.exceptions.RequestException as e:
        print(f"  [ERROR] GraphQL request failed: {e}")
        return {}


# ---------------------------------------------------------------------------
# GraphQL Queries
# ---------------------------------------------------------------------------

QUERY_USER_PROFILE = """
query userPublicProfile($username: String!) {
  matchedUser(username: $username) {
    username
    profile {
      ranking
      realName
    }
    submitStatsGlobal {
      acSubmissionNum {
        difficulty
        count
      }
    }
  }
}
"""

QUERY_USER_CONTEST = """
query userContestRankingInfo($username: String!) {
  userContestRanking(username: $username) {
    attendedContestsCount
    rating
    globalRanking
    topPercentage
  }
}
"""

QUERY_RECENT_AC_SUBMISSIONS = """
query recentAcSubmissions($username: String!, $limit: Int!) {
  recentAcSubmissionList(username: $username, limit: $limit) {
    id
    title
    titleSlug
    timestamp
    lang
    statusDisplay
  }
}
"""

QUERY_SUBMISSION_LIST = """
query submissionList($offset: Int!, $limit: Int!) {
  submissionList(offset: $offset, limit: $limit) {
    hasNext
    submissions {
      id
      title
      titleSlug
      timestamp
      lang
      statusDisplay
    }
  }
}
"""

QUERY_QUESTION_DATA = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    title
    titleSlug
    difficulty
    topicTags {
      name
      slug
    }
    content
    hints
  }
}
"""

QUERY_SUBMISSION_DETAILS = """
query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    code
    lang {
      name
      verboseName
    }
    runtime
    memory
    statusDisplay
    timestamp
    question {
      questionId
      questionFrontendId
      title
      titleSlug
    }
  }
}
"""

# ---------------------------------------------------------------------------
# Data fetching functions
# ---------------------------------------------------------------------------

def fetch_user_profile() -> dict:
    """Fetch public profile stats (solved counts, ranking)."""
    print(f"Fetching profile for {LEETCODE_USERNAME}...")
    data = graphql_request(QUERY_USER_PROFILE, {"username": LEETCODE_USERNAME})
    return data.get("matchedUser", {})


def fetch_contest_ranking() -> dict:
    """Fetch contest ranking info."""
    print(f"Fetching contest ranking for {LEETCODE_USERNAME}...")
    data = graphql_request(QUERY_USER_CONTEST, {"username": LEETCODE_USERNAME})
    return data.get("userContestRanking", {})


def fetch_all_ac_submissions() -> list:
    """Fetch all accepted submissions. Returns list sorted newest-first."""
    if not LEETCODE_SESSION:
        print(f"Fetching recent public submissions for {LEETCODE_USERNAME}...")
        data = graphql_request(
            QUERY_RECENT_AC_SUBMISSIONS,
            {"username": LEETCODE_USERNAME, "limit": 20},
        )
        submissions = data.get("recentAcSubmissionList", [])
        print(f"  Found {len(submissions)} accepted submissions")
        return submissions or []

    print(f"Fetching full submission history for {LEETCODE_USERNAME} (this may take a moment)...")
    offset = 0
    limit = 20
    ac_submissions = []
    
    while True:
        data = graphql_request(
            QUERY_SUBMISSION_LIST,
            {"offset": offset, "limit": limit}
        )
        sub_list = data.get("submissionList", {})
        if not sub_list:
            break
            
        subs = sub_list.get("submissions", [])
        for sub in subs:
            if sub.get("statusDisplay") == "Accepted":
                ac_submissions.append(sub)
                
        if not sub_list.get("hasNext"):
            break
            
        offset += limit
        time.sleep(REQUEST_DELAY)
        
    print(f"  Found {len(ac_submissions)} total accepted submissions")
    return ac_submissions


def fetch_question_data(title_slug: str) -> dict:
    """Fetch detailed question metadata."""
    time.sleep(REQUEST_DELAY)
    data = graphql_request(QUERY_QUESTION_DATA, {"titleSlug": title_slug})
    return data.get("question", {})


def fetch_submission_code(submission_id: int) -> dict:
    """Fetch source code for a specific submission (requires auth)."""
    if not LEETCODE_SESSION:
        return {}
    time.sleep(REQUEST_DELAY)
    data = graphql_request(QUERY_SUBMISSION_DETAILS, {"submissionId": submission_id})
    return data.get("submissionDetails", {})


# ---------------------------------------------------------------------------
# Sync state management
# ---------------------------------------------------------------------------

def load_sync_state() -> dict:
    """Load the sync state from disk."""
    if os.path.exists(SYNC_STATE_PATH):
        try:
            with open(SYNC_STATE_PATH, "r", encoding="utf-8") as f:
                return json.load(f)
        except (json.JSONDecodeError, IOError):
            pass
    return {"last_sync": None, "problems": {}}


def save_sync_state(state: dict):
    """Persist sync state to disk."""
    state["last_sync"] = datetime.now(timezone.utc).isoformat()
    with open(SYNC_STATE_PATH, "w", encoding="utf-8") as f:
        json.dump(state, f, indent=2, ensure_ascii=False)
    print(f"Sync state saved to {SYNC_STATE_PATH}")


# ---------------------------------------------------------------------------
# Local index helpers
# ---------------------------------------------------------------------------

def build_local_index() -> dict:
    """Scan leetcode/ directory and build an index of existing solutions.
    Returns dict keyed by title_slug → metadata dict + 'local_path'.
    """
    index = {}
    if not os.path.exists(LEETCODE_DIR):
        return index
    for difficulty in ["Easy", "Medium", "Hard"]:
        diff_dir = os.path.join(LEETCODE_DIR, difficulty)
        if not os.path.isdir(diff_dir):
            continue
        for folder_name in os.listdir(diff_dir):
            meta_path = os.path.join(diff_dir, folder_name, "metadata.json")
            if os.path.isfile(meta_path):
                try:
                    with open(meta_path, "r", encoding="utf-8") as f:
                        meta = json.load(f)
                    # Derive title slug from URL or folder name
                    slug = _slug_from_url(meta.get("url", "")) or folder_name
                    # Strip leading number prefix (e.g. "1-two-sum" → "two-sum")
                    if re.match(r"^\d+-", slug):
                        slug = re.sub(r"^\d+-", "", slug)
                    meta["_local_path"] = os.path.join(diff_dir, folder_name)
                    meta["_folder_name"] = folder_name
                    index[slug] = meta
                except Exception:
                    pass
    return index


def _slug_from_url(url: str) -> str:
    """Extract title slug from a LeetCode URL."""
    # e.g. https://leetcode.com/problems/two-sum/ → two-sum
    m = re.search(r"leetcode\.com/problems/([^/]+)", url)
    return m.group(1) if m else ""


def _make_folder_name(frontend_id: str, title_slug: str) -> str:
    """Create folder name like '1-two-sum'."""
    if frontend_id:
        return f"{frontend_id}-{title_slug}"
    return title_slug


# ---------------------------------------------------------------------------
# File writers
# ---------------------------------------------------------------------------

def _difficulty_badge_color(difficulty: str) -> str:
    return {"Easy": "green", "Medium": "yellow", "Hard": "red"}.get(difficulty, "blue")


def write_solution_folder(
    frontend_id: str,
    title: str,
    title_slug: str,
    difficulty: str,
    tags: list,
    solved_timestamp: int,
    submissions: list,  # list of (lang_slug, code) tuples
):
    """Create or update the solution folder for a problem."""
    folder_name = _make_folder_name(frontend_id, title_slug)
    folder_path = os.path.join(LEETCODE_DIR, difficulty, folder_name)
    os.makedirs(folder_path, exist_ok=True)

    solved_date = datetime.fromtimestamp(solved_timestamp).strftime("%Y-%m-%d")
    url = f"https://leetcode.com/problems/{title_slug}/"

    # Determine languages
    lang_canonicals = []
    for lang_slug, _ in submissions:
        canonical = LANG_CANONICAL.get(lang_slug, lang_slug)
        if canonical not in lang_canonicals:
            lang_canonicals.append(canonical)

    # --- metadata.json ---
    metadata = {
        "id": str(frontend_id),
        "title": title,
        "url": url,
        "platform": "LeetCode",
        "difficulty": difficulty,
        "tags": tags,
        "solved_date": solved_date,
        "languages": lang_canonicals,
    }
    meta_path = os.path.join(folder_path, "metadata.json")
    with open(meta_path, "w", encoding="utf-8") as f:
        json.dump(metadata, f, indent=2, ensure_ascii=False)

    # --- README.md ---
    badge_color = _difficulty_badge_color(difficulty)
    tags_md = ", ".join([f"`{t}`" for t in tags]) if tags else "—"

    readme = f"""# {frontend_id}. {title}

![Difficulty: {difficulty}](https://img.shields.io/badge/Difficulty-{difficulty}-{badge_color}?style=flat-square)
[![Platform: LeetCode](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=flat-square&logo=LeetCode&logoColor=white)]({url})

## 📝 Problem Description

[View on LeetCode]({url})

## 🏷️ Tags

{tags_md}

## 💡 Solution Approach

*Automatically synced from LeetCode accepted submissions.*

---

## 💻 Code Implementations

"""
    for lang_slug, code in submissions:
        canonical = LANG_CANONICAL.get(lang_slug, lang_slug)
        ext = LANG_EXT_MAP.get(lang_slug, ".txt")
        syntax = _lang_syntax_name(lang_slug)
        readme += f"### {canonical.upper()}\n\n"
        readme += f"```{syntax}\n// Refer to solution{ext} for the full implementation\n```\n\n"

    readme_path = os.path.join(folder_path, "README.md")
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(readme.strip() + "\n")

    # --- Solution code files ---
    for lang_slug, code in submissions:
        ext = LANG_EXT_MAP.get(lang_slug, ".txt")
        code_path = os.path.join(folder_path, f"solution{ext}")
        if code:
            with open(code_path, "w", encoding="utf-8") as f:
                f.write(code + "\n")
        # If no code (unauthenticated), only write if file doesn't exist
        elif not os.path.exists(code_path):
            with open(code_path, "w", encoding="utf-8") as f:
                f.write(f"// Solution code not available (LEETCODE_SESSION not provided)\n")

    print(f"  ✅ {frontend_id}. {title} ({difficulty}) — {', '.join(lang_canonicals)}")


def _lang_syntax_name(lang_slug: str) -> str:
    """Map LeetCode lang slug to markdown syntax highlighter name."""
    mapping = {
        "python": "python", "python3": "python", "cpp": "cpp", "c": "c",
        "java": "java", "javascript": "javascript", "typescript": "typescript",
        "golang": "go", "rust": "rust", "ruby": "ruby", "swift": "swift",
        "kotlin": "kotlin", "csharp": "csharp", "scala": "scala",
        "php": "php", "dart": "dart",
    }
    return mapping.get(lang_slug, lang_slug)


# ---------------------------------------------------------------------------
# Core sync logic
# ---------------------------------------------------------------------------

def run_sync():
    """Main sync entry point."""
    print("=" * 60)
    print("  LeetCode Sync — Fetching & Syncing Solutions")
    print("=" * 60)
    print()

    if not LEETCODE_SESSION:
        print("[WARN] LEETCODE_SESSION not set. Will sync metadata only (no source code).")
        print("       To fetch code, set the LEETCODE_SESSION environment variable.")
        print()

    # 1. Load state & local index
    state = load_sync_state()
    local_index = build_local_index()
    print(f"Local index: {len(local_index)} existing LeetCode solutions found")
    print()

    # 2. Fetch all accepted submissions
    all_submissions = fetch_all_ac_submissions()
    if not all_submissions:
        print("[WARN] No accepted submissions found. Exiting.")
        save_sync_state(state)
        return

    # 3. Group submissions by problem (title_slug)
    #    Keep only the most recent submission per (problem, language) pair
    problem_subs = {}  # title_slug → {lang_slug → submission}
    for sub in all_submissions:
        slug = sub.get("titleSlug", "")
        lang = sub.get("lang", "unknown")
        if not slug:
            continue
        if slug not in problem_subs:
            problem_subs[slug] = {}
        # Keep the latest submission per language
        existing = problem_subs[slug].get(lang)
        if not existing or int(sub.get("timestamp", 0)) > int(existing.get("timestamp", 0)):
            problem_subs[slug][lang] = sub

    print(f"Unique solved problems: {len(problem_subs)}")
    print()

    # 4. Determine which problems need syncing
    problems_to_sync = []
    for slug, lang_subs in problem_subs.items():
        # Find the latest timestamp across all languages for this problem
        max_ts = max(int(s.get("timestamp", 0)) for s in lang_subs.values())

        # Check sync state
        prev = state.get("problems", {}).get(slug, {})
        prev_ts = prev.get("last_timestamp", 0)

        # Check if exists locally
        is_local = slug in local_index

        # Sync if: new problem OR newer submission since last sync
        if not is_local or max_ts > prev_ts:
            problems_to_sync.append((slug, lang_subs, max_ts))

    print(f"Problems to sync: {len(problems_to_sync)} (new or updated)")
    if not problems_to_sync:
        print("Everything is up to date! Nothing to sync.")
        save_sync_state(state)
        return

    print()

    # 5. Fetch details and write files for each problem
    synced = 0
    for slug, lang_subs, max_ts in problems_to_sync:
        print(f"Syncing: {slug}...")

        # Fetch question metadata
        qdata = fetch_question_data(slug)
        if not qdata:
            print(f"  [SKIP] Could not fetch question data for {slug}")
            continue

        frontend_id = qdata.get("questionFrontendId", "")
        title = qdata.get("title", slug)
        difficulty = qdata.get("difficulty", "Medium")
        tags = [t["name"] for t in qdata.get("topicTags", [])]

        # Fetch code for each language submission
        submissions = []
        for lang_slug, sub_meta in lang_subs.items():
            sub_id = int(sub_meta.get("id", 0))
            code = ""
            if sub_id and LEETCODE_SESSION:
                details = fetch_submission_code(sub_id)
                if details:
                    code = details.get("code", "")
            submissions.append((lang_slug, code))

        # Find the earliest timestamp for solved_date
        earliest_ts = min(int(s.get("timestamp", max_ts)) for s in lang_subs.values())

        # Write files
        write_solution_folder(
            frontend_id=frontend_id,
            title=title,
            title_slug=slug,
            difficulty=difficulty,
            tags=tags,
            solved_timestamp=earliest_ts,
            submissions=submissions,
        )

        # Update state
        if "problems" not in state:
            state["problems"] = {}
        state["problems"][slug] = {
            "last_submission_id": str(max(int(s.get("id", 0)) for s in lang_subs.values())),
            "last_timestamp": max_ts,
            "languages": list(lang_subs.keys()),
        }
        synced += 1

    print()
    print(f"Sync complete! {synced} problems synced.")

    # 6. Save profile stats to state (for sync_readme.py to use)
    profile = fetch_user_profile()
    contest = fetch_contest_ranking()
    state["profile"] = {
        "username": LEETCODE_USERNAME,
        "ranking": profile.get("profile", {}).get("ranking", 0),
        "solved_stats": {},
        "contest": {},
    }
    # Parse solved stats
    for item in profile.get("submitStatsGlobal", {}).get("acSubmissionNum", []):
        diff = item.get("difficulty", "All")
        state["profile"]["solved_stats"][diff] = item.get("count", 0)

    if contest:
        state["profile"]["contest"] = {
            "rating": round(contest.get("rating", 0), 1),
            "global_ranking": contest.get("globalRanking", 0),
            "top_percentage": round(contest.get("topPercentage", 0), 2),
            "attended": contest.get("attendedContestsCount", 0),
        }

    save_sync_state(state)
    print()
    print("✨ All done!")


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

if __name__ == "__main__":
    run_sync()
