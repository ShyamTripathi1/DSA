import os
import json
import re
import sys
import subprocess
from datetime import datetime

# Path setups
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_DIR = os.path.dirname(SCRIPT_DIR)
SYNC_SCRIPT = os.path.join(SCRIPT_DIR, "sync_readme.py")

# Mappings for selections
PLATFORMS = {
    "1": "LeetCode",
    "2": "GeeksforGeeks",
    "3": "HackerRank",
    "4": "Topics"
}

DIFFICULTIES = {
    "1": "Easy",
    "2": "Medium",
    "3": "Hard",
    # GeeksforGeeks specific options if selected
    "4": "School",
    "5": "Basic"
}

LANGUAGES = {
    "1": ("cpp", "solution.cpp", "// C++ Solution\n#include <iostream>\n#include <vector>\nusing namespace std;\n\nclass Solution {\npublic:\n    // Add solution here\n};\n\nint main() {\n    return 0;\n}\n"),
    "2": ("java", "Solution.java", "// Java Solution\nimport java.util.*;\n\npublic class Solution {\n    // Add solution here\n    public static void main(String[] args) {\n        \n    }\n}\n"),
    "3": ("python", "solution.py", "# Python Solution\n\nclass Solution:\n    def solve(self):\n        pass\n\nif __name__ == '__main__':\n    pass\n"),
    "4": ("javascript", "solution.js", "// JavaScript Solution\n\n// Add solution here\nfunction solve() {\n    \n}\n"),
    "5": ("go", "solution.go", "// Go Solution\npackage main\n\nimport \"fmt\"\n\nfunc main() {\n    \n}\n")
}

def clean_slug(title):
    # Convert to lowercase, remove non-alphanumeric, replace spaces with hyphen
    slug = title.strip().lower()
    slug = re.sub(r'[^a-z0-9\s-]', '', slug)
    slug = re.sub(r'[\s-]+', '-', slug)
    return slug

def prompt_choice(prompt_text, choices, default=None):
    print(f"\n{prompt_text}")
    for k, v in choices.items():
        print(f"  [{k}] {v if not isinstance(v, tuple) else v[0].upper()}")
    
    while True:
        choice = input("Select an option: ").strip()
        if not choice and default:
            return default
        if choice in choices:
            return choice
        print("Invalid choice, please try again.")

def main():
    print("==" * 30)
    print("      DSA Solution Boilerplate Creator")
    print("==" * 30)

    # 1. Select Platform
    plat_key = prompt_choice("Select Coding Platform:", PLATFORMS, "1")
    platform = PLATFORMS[plat_key]

    # 2. Select Difficulty
    if platform == "GeeksforGeeks":
        diff_choices = DIFFICULTIES
    else:
        diff_choices = {k: v for k, v in DIFFICULTIES.items() if k in ["1", "2", "3"]}
        
    diff_key = prompt_choice("Select Problem Difficulty:", diff_choices, "1")
    difficulty = diff_choices[diff_key]

    # 3. Problem Details
    problem_id = input("\nEnter Problem ID (optional, e.g. 1): ").strip()
    
    while True:
        problem_title = input("Enter Problem Title (required): ").strip()
        if problem_title:
            break
        print("Title cannot be empty!")

    problem_url = input("Enter Problem URL (optional): ").strip()
    
    tags_input = input("Enter categories/tags (comma-separated, e.g. Array, Hash Table): ").strip()
    tags = [t.strip() for t in tags_input.split(",") if t.strip()] if tags_input else []

    # 4. Select Programming Languages (Multi-select)
    print("\nSelect programming languages (comma-separated, e.g. 1,3):")
    for k, v in LANGUAGES.items():
        print(f"  [{k}] {v[0].upper()}")
    
    selected_langs = []
    while True:
        lang_keys = input("Select languages (default: 1 for C++): ").strip()
        if not lang_keys:
            selected_langs = [LANGUAGES["1"]]
            break
            
        keys = [k.strip() for k in lang_keys.split(",")]
        valid = True
        for key in keys:
            if key not in LANGUAGES:
                print(f"Invalid choice '{key}'. Please enter valid numbers separated by commas.")
                valid = False
                break
        if valid:
            selected_langs = [LANGUAGES[k] for k in keys]
            break

    # 5. Create Directory Structure
    # Normalize platform for path (lowercase)
    platform_dir = platform.lower().replace(" ", "")
    
    # Target folder names
    slug = clean_slug(problem_title)
    folder_name = f"{problem_id}-{slug}" if problem_id else slug
    
    # Path is: <platform_dir>/<difficulty>/<folder_name>
    # Note: capitalize difficulty for folder structure sorting
    dir_name = os.path.join(REPO_DIR, platform_dir, difficulty, folder_name)
    
    if os.path.exists(dir_name):
        print(f"\n[Warning] Directory already exists: {dir_name}")
        overwrite = input("Do you want to overwrite? (y/N): ").strip().lower()
        if overwrite != 'y':
            print("Operation cancelled.")
            sys.exit(0)
    else:
        os.makedirs(dir_name, exist_ok=True)

    # 6. Create files
    lang_names = [l[0] for l in selected_langs]
    solved_date = datetime.now().strftime("%Y-%m-%d")
    
    # Write metadata.json
    metadata = {
        "id": problem_id,
        "title": problem_title,
        "url": problem_url,
        "platform": platform,
        "difficulty": difficulty,
        "tags": tags,
        "solved_date": solved_date,
        "languages": lang_names
    }
    
    with open(os.path.join(dir_name, "metadata.json"), "w", encoding="utf-8") as f:
        json.dump(metadata, f, indent=2, ensure_ascii=False)

    # Write problem-specific README.md
    diff_badge = f"![Difficulty: {difficulty}](https://img.shields.io/badge/Difficulty-{difficulty}-"
    badge_colors = {
        "Easy": "green", "Medium": "yellow", "Hard": "red",
        "School": "green", "Basic": "green"
    }
    color = badge_colors.get(difficulty, "blue")
    diff_badge += f"{color}?style=flat-square)"

    problem_readme = f"""# {problem_title}

{diff_badge}
[![Platform: {platform}](https://img.shields.io/badge/Platform-{platform}-blue?style=flat-square)]({problem_url if problem_url else '#'})

## 📝 Problem Description

{"Add problem description here..." if not problem_url else f"[Link to Problem]({problem_url})\n\nAdd problem description here..."}

## 💡 Solution Approach

Add your conceptual explanation, algorithm details, or patterns used (e.g. Two Pointers, Sliding Window) here...

### Complexity Analysis

- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(1)$

---

## 💻 Code Implementations

"""

    for lang_info in selected_langs:
        lang_name, file_name, boilerplate = lang_info
        # Append logic to problem README
        lang_syntax = "cpp" if lang_name == "cpp" else (
            "python" if lang_name == "python" else (
                "java" if lang_name == "java" else (
                    "javascript" if lang_name == "javascript" else "go"
                )
            )
        )
        problem_readme += f"### {lang_name.upper()}\n\n"
        problem_readme += f"``` {lang_syntax}\n// Refer to {file_name} for the full implementation\n```\n\n"
        
        # Write individual boilerplate code files if not already exist
        code_file_path = os.path.join(dir_name, file_name)
        if not os.path.exists(code_file_path):
            with open(code_file_path, "w", encoding="utf-8") as f:
                f.write(boilerplate)
            print(f"Created code template: {file_name}")

    with open(os.path.join(dir_name, "README.md"), "w", encoding="utf-8") as f:
        f.write(problem_readme.strip() + "\n")
    print(f"Created README.md for the problem.")

    print(f"\n[Success] Successfully set up solution template at: {dir_name}\n")
    
    # 7. Run sync script to rebuild stats
    if os.path.exists(SYNC_SCRIPT):
        print("Running sync_readme.py to update repository stats...")
        subprocess.run([sys.executable, SYNC_SCRIPT], cwd=REPO_DIR)
    else:
        print("[Warning] sync_readme.py not found, stats were not synced.")

if __name__ == "__main__":
    main()
