import os
import json
import re
from datetime import datetime

# Define workspace paths
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_DIR = os.path.dirname(SCRIPT_DIR)
DASHBOARD_DIR = os.path.join(REPO_DIR, "dashboard")
README_PATH = os.path.join(REPO_DIR, "README.md")

# Profile Links
GITHUB_PROFILE = "https://github.com/ShyamTripathi1"
LEETCODE_PROFILE = "https://leetcode.com/u/ShyamTripathi12/"
GFG_PROFILE = "https://www.geeksforgeeks.org/profile/tripathin2cv"
HACKERRANK_PROFILE = "https://www.hackerrank.com/profile/2313058_CSDS1C"

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

def generate_readme(problems, stats):
    # Badges markdown
    badges = (
        f"[![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=white)]({LEETCODE_PROFILE}) "
        f"[![GeeksforGeeks](https://img.shields.io/badge/GeeksforGeeks-298D46?style=for-the-badge&logo=GeeksforGeeks&logoColor=white)]({GFG_PROFILE}) "
        f"[![HackerRank](https://img.shields.io/badge/HackerRank-2EC866?style=for-the-badge&logo=HackerRank&logoColor=white)]({HACKERRANK_PROFILE}) "
        f"[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=GitHub&logoColor=white)]({GITHUB_PROFILE})"
    )
    
    # Platform Solved Counters
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

    readme_content = f"""# 🏆 Shyam Tripathi's Problem Solving & DSA Journey

Welcome to my central repository for Data Structures, Algorithms, and coding challenge solutions. This repository organizes my solutions from LeetCode, GeeksforGeeks, and HackerRank, complete with automated progress syncing and a local stats visualizer.

{badges}

---

## 📊 Performance Statistics

| Platform | Progress Bar | Solved | Easy | Medium | Hard |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **LeetCode** | `{lc_bar}` | **{lc_total}** | {stats["leetcode"]["Easy"]} | {stats["leetcode"]["Medium"]} | {stats["leetcode"]["Hard"]} |
| **GeeksforGeeks** | `{gfg_bar}` | **{gfg_total}** | {stats["geeksforgeeks"]["Easy"]} | {stats["geeksforgeeks"]["Medium"]} | {stats["geeksforgeeks"]["Hard"]} |
| **HackerRank** | `{hr_bar}` | **{hr_total}** | {stats["hackerrank"]["Easy"]} | {stats["hackerrank"]["Medium"]} | {stats["hackerrank"]["Hard"]} |
| **Topic-wise / Custom** | - | **{tp_total}** | {stats["topics"]["Easy"]} | {stats["topics"]["Medium"]} | {stats["topics"]["Hard"]} |
| **Total Progress** | `{make_progress_bar(total, total)}` | **{total}** | **{stats["leetcode"]["Easy"] + stats["geeksforgeeks"]["Easy"] + stats["hackerrank"]["Easy"] + stats["topics"]["Easy"]}** | **{stats["leetcode"]["Medium"] + stats["geeksforgeeks"]["Medium"] + stats["hackerrank"]["Medium"] + stats["topics"]["Medium"]}** | **{stats["leetcode"]["Hard"] + stats["geeksforgeeks"]["Hard"] + stats["hackerrank"]["Hard"] + stats["topics"]["Hard"]}** |

**Languages Used:** {langs_md}

> [!TIP]
> **📈 Interactive Dashboard:** Open the [dashboard/index.html](file:///{DASHBOARD_DIR.replace("\\", "/")}/index.html) in your browser to view interactive visual charts of my stats and filter/search solved problems!

---

## 🚀 Automation Utilities

This repository is equipped with automation tools to make solving and logging problems frictionless:

- **Add a new solution:** Run `python scripts/add_solution.py` from the root directory. It will interactively ask for the platform, problem title, link, difficulty, and create the directories, boilerplate code files, and custom READMEs.
- **Sync Stats:** The add script automatically calls `python scripts/sync_readme.py` to regenerate the tables above and the data file for the local web dashboard. You can also run it manually at any time.

---

## 📚 Problem Directory

Below are the solved problems categorized by platform.

"""
    
    # 1. Recent solutions
    recent_problems = problems[:10]
    if recent_problems:
        readme_content += "### ⏱️ Recently Solved\n\n"
        readme_content += "| Date | Platform | Problem | Difficulty | Languages | Link | \n"
        readme_content += "| :---: | :--- | :--- | :---: | :---: | :---: |\n"
        for p in recent_problems:
            p_id = f"{p['id']}. " if p.get("id") else ""
            title = p["title"]
            diff_emoji = "🟢 Easy" if normalize_difficulty(p["platform"], p["difficulty"]) == "Easy" else ("🟡 Medium" if normalize_difficulty(p["platform"], p["difficulty"]) == "Medium" else "🔴 Hard")
            langs = ", ".join([l.upper() for l in p.get("languages", [])])
            p_link = f"[Solution](./{p['path']})"
            ext_link = f"[Problem Link]({p['url']})" if p.get("url") else "N/A"
            
            readme_content += f"| {p.get('solved_date', 'N/A')} | {p['platform']} | {p_id}{title} | {diff_emoji} | {langs} | {p_link} / {ext_link} |\n"
        readme_content += "\n---\n\n"

    # 2. Group by Platform
    platforms = ["LeetCode", "GeeksforGeeks", "HackerRank", "Topics"]
    for plat in platforms:
        plat_problems = [p for p in problems if (p.get("platform", "").lower() == plat.lower() or (plat == "Topics" and p.get("platform", "").lower() not in ["leetcode", "geeksforgeeks", "hackerrank"]))]
        
        if not plat_problems:
            continue
            
        readme_content += f"<details>\n<summary><b>📂 {plat} Solutions ({len(plat_problems)})</b></summary>\n\n"
        readme_content += "| ID | Problem Title | Difficulty | Languages | Solutions |\n"
        readme_content += "| :---: | :--- | :---: | :---: | :--- |\n"
        
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
            
            readme_content += f"| {p_id} | {title} | {diff_emoji} | {langs} | {links_str} |\n"
            
        readme_content += "\n</details>\n\n"
        
    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(readme_content.strip() + "\n")
    print(f"Successfully generated README.md at {README_PATH}")

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
