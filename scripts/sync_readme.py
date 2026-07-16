import os
import json
import re
from datetime import datetime

# Define workspace paths
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_DIR = os.path.dirname(SCRIPT_DIR)
DASHBOARD_DIR = os.path.join(REPO_DIR, "dashboard")
README_PATH = os.path.join(REPO_DIR, "README.md")
SYNC_STATE_PATH = os.path.join(SCRIPT_DIR, "sync_state.json")

# Profile Links
GITHUB_PROFILE = "https://github.com/ShyamTripathi1"
LEETCODE_PROFILE = "https://leetcode.com/u/ShyamTripathi12/"
GFG_PROFILE = "https://www.geeksforgeeks.org/profile/tripathin2cv"
HACKERRANK_PROFILE = "https://www.hackerrank.com/profile/2313058_CSDS1C"

# Section markers
STATS_START = "<!--START_SECTION:leetcode-stats-->"
STATS_END = "<!--END_SECTION:leetcode-stats-->"
INDEX_START = "<!--START_SECTION:problem-index-->"
INDEX_END = "<!--END_SECTION:problem-index-->"


# Map GFG/HR difficulties to standard
def normalize_difficulty(platform, diff):
    diff = diff.strip().capitalize()
    if platform.lower() == "geeksforgeeks":
        if diff in ["School", "Basic", "Easy"]:
            return "Easy"
        elif diff == "Medium":
            return "Medium"
        elif diff in ["Hard", "Expert"]:
            return "Hard"
    return diff

def make_progress_bar(solved, total=100, length=20):
    if total == 0:
        return "░" * length
    filled_len = int(round(length * solved / float(total)))
    return "█" * filled_len + "░" * (length - filled_len)

def scan_problems():
    problems = []
    # Directories to scan
    scan_dirs = ["leetcode", "geeksforgeeks", "hackerrank", "topics"]
    
    for folder in scan_dirs:
        folder_path = os.path.join(REPO_DIR, folder)
        if not os.path.exists(folder_path):
            continue
            
        for root, dirs, files in os.walk(folder_path):
            if "metadata.json" in files:
                meta_path = os.path.join(root, "metadata.json")
                try:
                    with open(meta_path, "r", encoding="utf-8") as f:
                        data = json.load(f)
                    
                    # Compute relative path from REPO_DIR
                    rel_path = os.path.relpath(root, REPO_DIR).replace("\\", "/")
                    data["path"] = rel_path
                    problems.append(data)
                except Exception as e:
                    print(f"Error reading {meta_path}: {e}")
                    
    # Sort problems by solved date (newest first), then by ID or title
    def sort_key(p):
        date_str = p.get("solved_date", "")
        try:
            date_obj = datetime.strptime(date_str, "%Y-%m-%d")
        except ValueError:
            date_obj = datetime.min
        # Secondary keys: Platform, Title
        return (date_obj, p.get("platform", ""), p.get("title", ""))
        
    problems.sort(key=sort_key, reverse=True)
    return problems

def calculate_stats(problems):
    stats = {
        "total": len(problems),
        "leetcode": {"total": 0, "Easy": 0, "Medium": 0, "Hard": 0},
        "geeksforgeeks": {"total": 0, "Easy": 0, "Medium": 0, "Hard": 0},
        "hackerrank": {"total": 0, "Easy": 0, "Medium": 0, "Hard": 0},
        "topics": {"total": 0, "Easy": 0, "Medium": 0, "Hard": 0},
        "languages": {}
    }
    
    for p in problems:
        platform = p.get("platform", "").lower().replace(" ", "")
        diff = p.get("difficulty", "Easy")
        norm_diff = normalize_difficulty(p.get("platform", ""), diff)
        
        # Increment platform stats
        if platform in stats:
            stats[platform]["total"] += 1
            if norm_diff in ["Easy", "Medium", "Hard"]:
                stats[platform][norm_diff] += 1
        else:
            # Fallback for topics if it doesn't match standard
            stats["topics"]["total"] += 1
            if norm_diff in ["Easy", "Medium", "Hard"]:
                stats["topics"][norm_diff] += 1
                
        # Languages stats
        for lang in p.get("languages", []):
            lang_key = lang.lower()
            stats["languages"][lang_key] = stats["languages"].get(lang_key, 0) + 1
            
    return stats


def load_leetcode_extra_stats():
    """Load contest rating / ranking from sync_state.json if available."""
    if not os.path.exists(SYNC_STATE_PATH):
        return {}
    try:
        with open(SYNC_STATE_PATH, "r", encoding="utf-8") as f:
            state = json.load(f)
        return state.get("profile", {})
    except Exception:
        return {}


def generate_stats_section(stats):
    """Generate the stats table markdown (between markers)."""
    lc_total = stats["leetcode"]["total"]
    gfg_total = stats["geeksforgeeks"]["total"]
    hr_total = stats["hackerrank"]["total"]
    tp_total = stats["topics"]["total"]
    total = stats["total"]
    
    # Progress bars
    lc_bar = make_progress_bar(lc_total, total) if total > 0 else make_progress_bar(0)
    gfg_bar = make_progress_bar(gfg_total, total) if total > 0 else make_progress_bar(0)
    hr_bar = make_progress_bar(hr_total, total) if total > 0 else make_progress_bar(0)
    
    # Languages list markdown
    langs_md = ", ".join([f"`{lang.upper()} ({count})`" for lang, count in sorted(stats["languages"].items(), key=lambda x: x[1], reverse=True)])
    if not langs_md:
        langs_md = "None yet"

    total_easy = stats["leetcode"]["Easy"] + stats["geeksforgeeks"]["Easy"] + stats["hackerrank"]["Easy"] + stats["topics"]["Easy"]
    total_medium = stats["leetcode"]["Medium"] + stats["geeksforgeeks"]["Medium"] + stats["hackerrank"]["Medium"] + stats["topics"]["Medium"]
    total_hard = stats["leetcode"]["Hard"] + stats["geeksforgeeks"]["Hard"] + stats["hackerrank"]["Hard"] + stats["topics"]["Hard"]

    section = f"""| Platform | Progress Bar | Solved | Easy | Medium | Hard |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **LeetCode** | `{lc_bar}` | **{lc_total}** | {stats["leetcode"]["Easy"]} | {stats["leetcode"]["Medium"]} | {stats["leetcode"]["Hard"]} |
| **GeeksforGeeks** | `{gfg_bar}` | **{gfg_total}** | {stats["geeksforgeeks"]["Easy"]} | {stats["geeksforgeeks"]["Medium"]} | {stats["geeksforgeeks"]["Hard"]} |
| **HackerRank** | `{hr_bar}` | **{hr_total}** | {stats["hackerrank"]["Easy"]} | {stats["hackerrank"]["Medium"]} | {stats["hackerrank"]["Hard"]} |
| **Topic-wise / Custom** | - | **{tp_total}** | {stats["topics"]["Easy"]} | {stats["topics"]["Medium"]} | {stats["topics"]["Hard"]} |
| **Total Progress** | `{make_progress_bar(total, total)}` | **{total}** | **{total_easy}** | **{total_medium}** | **{total_hard}** |

**Languages Used:** {langs_md}"""

    # Add contest rating if available
    lc_profile = load_leetcode_extra_stats()
    contest = lc_profile.get("contest", {})
    ranking = lc_profile.get("ranking", 0)

    if contest or ranking:
        section += "\n"
        if ranking:
            section += f"\n**LeetCode Ranking:** #{ranking:,}"
        if contest.get("rating"):
            section += f" · **Contest Rating:** {contest['rating']}"
        if contest.get("attended"):
            section += f" · **Contests Attended:** {contest['attended']}"
        if contest.get("top_percentage"):
            section += f" · **Top:** {contest['top_percentage']}%"

    return section


def generate_index_section(problems):
    """Generate the full problem directory markdown (between markers)."""
    content = ""

    # 1. Recent solutions
    recent_problems = problems[:10]
    if recent_problems:
        content += "### ⏱️ Recently Solved\n\n"
        content += "| Date | Platform | Problem | Difficulty | Languages | Link | \n"
        content += "| :---: | :--- | :--- | :---: | :---: | :---: |\n"
        for p in recent_problems:
            p_id = f"{p['id']}. " if p.get("id") else ""
            title = p["title"]
            diff_emoji = "🟢 Easy" if normalize_difficulty(p["platform"], p["difficulty"]) == "Easy" else ("🟡 Medium" if normalize_difficulty(p["platform"], p["difficulty"]) == "Medium" else "🔴 Hard")
            langs = ", ".join([l.upper() for l in p.get("languages", [])])
            p_link = f"[Solution](./{p['path']})"
            ext_link = f"[Problem Link]({p['url']})" if p.get("url") else "N/A"
            
            content += f"| {p.get('solved_date', 'N/A')} | {p['platform']} | {p_id}{title} | {diff_emoji} | {langs} | {p_link} / {ext_link} |\n"
        content += "\n---\n\n"

    # 2. Group by Platform
    platforms = ["LeetCode", "GeeksforGeeks", "HackerRank", "Topics"]
    for plat in platforms:
        plat_problems = [p for p in problems if (p.get("platform", "").lower() == plat.lower() or (plat == "Topics" and p.get("platform", "").lower() not in ["leetcode", "geeksforgeeks", "hackerrank"]))]
        
        if not plat_problems:
            continue
            
        content += f"<details>\n<summary><b>📂 {plat} Solutions ({len(plat_problems)})</b></summary>\n\n"
        content += "| ID | Problem Title | Difficulty | Languages | Solutions |\n"
        content += "| :---: | :--- | :---: | :---: | :--- |\n"
        
        # Sort these problems by ID if numeric, else title
        def sub_sort_key(p):
            p_id = p.get("id", "")
            if not p_id:
                return (float('inf'), p.get("title", ""))
            # Check if numeric
            nums = re.findall(r'\d+', str(p_id))
            if nums:
                return (int(nums[0]), p.get("title", ""))
            return (float('inf'), str(p_id))
            
        plat_problems.sort(key=sub_sort_key)
        
        for p in plat_problems:
            p_id = p.get("id", "-")
            title = p["title"]
            diff = p["difficulty"]
            diff_emoji = "🟢 " + diff if normalize_difficulty(p["platform"], diff) == "Easy" else ("🟡 " + diff if normalize_difficulty(p["platform"], diff) == "Medium" else "🔴 " + diff)
            langs = ", ".join([f"[`{l.upper()}`](./{p['path']})" for l in p.get("languages", [])])
            desc_link = f"[Problem Description](./{p['path']}/README.md)"
            ext_link = f"[External Link]({p['url']})" if p.get("url") else ""
            links_str = f"{desc_link}" + (f" | {ext_link}" if ext_link else "")
            
            content += f"| {p_id} | {title} | {diff_emoji} | {langs} | {links_str} |\n"
            
        content += "\n</details>\n\n"

    return content.strip()


def _replace_section(readme: str, start_marker: str, end_marker: str, new_content: str) -> str:
    """Replace content between markers. If markers don't exist, return readme unchanged."""
    pattern = re.compile(
        re.escape(start_marker) + r".*?" + re.escape(end_marker),
        re.DOTALL,
    )
    replacement = f"{start_marker}\n{new_content}\n{end_marker}"
    if pattern.search(readme):
        return pattern.sub(replacement, readme)
    return readme


def generate_readme(problems, stats):
    """Generate or update the README with section markers."""

    # Check if README exists and has markers
    if os.path.exists(README_PATH):
        with open(README_PATH, "r", encoding="utf-8") as f:
            existing = f.read()

        has_stats_markers = STATS_START in existing and STATS_END in existing
        has_index_markers = INDEX_START in existing and INDEX_END in existing

        if has_stats_markers or has_index_markers:
            # Marker-based partial update
            updated = existing
            if has_stats_markers:
                stats_content = generate_stats_section(stats)
                updated = _replace_section(updated, STATS_START, STATS_END, stats_content)
            if has_index_markers:
                index_content = generate_index_section(problems)
                updated = _replace_section(updated, INDEX_START, INDEX_END, index_content)

            with open(README_PATH, "w", encoding="utf-8") as f:
                f.write(updated)
            print(f"Successfully updated README.md (marker-based) at {README_PATH}")
            return

    # Fallback: full rewrite (insert markers this time)
    _full_rewrite_readme(problems, stats)


def _full_rewrite_readme(problems, stats):
    """Full rewrite of README.md — inserts section markers for future partial updates."""
    # Badges markdown
    badges = (
        f"[![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=white)]({LEETCODE_PROFILE}) "
        f"[![GeeksforGeeks](https://img.shields.io/badge/GeeksforGeeks-298D46?style=for-the-badge&logo=GeeksforGeeks&logoColor=white)]({GFG_PROFILE}) "
        f"[![HackerRank](https://img.shields.io/badge/HackerRank-2EC866?style=for-the-badge&logo=HackerRank&logoColor=white)]({HACKERRANK_PROFILE}) "
        f"[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=GitHub&logoColor=white)]({GITHUB_PROFILE})"
    )

    stats_section = generate_stats_section(stats)
    index_section = generate_index_section(problems)

    readme_content = f"""# 🏆 Shyam Tripathi's Problem Solving & DSA Journey

Welcome to my central repository for Data Structures, Algorithms, and coding challenge solutions. This repository organizes my solutions from LeetCode, GeeksforGeeks, and HackerRank, complete with automated progress syncing and a local stats visualizer.

{badges}

---

## 📊 Performance Statistics

{STATS_START}
{stats_section}
{STATS_END}

> [!TIP]
> **📈 Interactive Dashboard:** Open the [dashboard/index.html](file:///{DASHBOARD_DIR.replace(chr(92), "/")}/index.html) in your browser to view interactive visual charts of my stats and filter/search solved problems!

---

## 🚀 Automation Utilities

This repository is equipped with automation tools to make solving and logging problems frictionless:

- **Add a new solution:** Run `python scripts/add_solution.py` from the root directory. It will interactively ask for the platform, problem title, link, difficulty, and create the directories, boilerplate code files, and custom READMEs.
- **Sync Stats:** The add script automatically calls `python scripts/sync_readme.py` to regenerate the tables above and the data file for the local web dashboard. You can also run it manually at any time.
- **LeetCode Auto-Sync:** A GitHub Actions workflow runs daily to fetch new accepted LeetCode submissions and sync them into the repo. See `.github/workflows/leetcode-sync.yml`.

---

## 📚 Problem Directory

Below are the solved problems categorized by platform.

{INDEX_START}
{index_section}
{INDEX_END}
"""

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(readme_content.strip() + "\n")
    print(f"Successfully generated README.md (full rewrite with markers) at {README_PATH}")


def update_dashboard_data(problems, stats):
    if not os.path.exists(DASHBOARD_DIR):
        os.makedirs(DASHBOARD_DIR)
        
    dashboard_data_path = os.path.join(DASHBOARD_DIR, "data.js")
    
    data = {
        "stats": stats,
        "problems": problems,
        "last_updated": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    }
    
    with open(dashboard_data_path, "w", encoding="utf-8") as f:
        f.write(f"const dashboardData = {json.dumps(data, indent=2, ensure_ascii=False)};")
    print(f"Successfully generated dashboard data at {dashboard_data_path}")

if __name__ == "__main__":
    print("Scanning repository for solutions...")
    problems_list = scan_problems()
    stats_data = calculate_stats(problems_list)
    generate_readme(problems_list, stats_data)
    update_dashboard_data(problems_list, stats_data)
