import os
import json
import subprocess
import sys
from datetime import datetime

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_DIR = os.path.dirname(SCRIPT_DIR)
SYNC_SCRIPT = os.path.join(SCRIPT_DIR, "sync_readme.py")

# Sample problems to seed
SAMPLE_PROBLEMS = [
    {
        "id": "1",
        "title": "Two Sum",
        "url": "https://leetcode.com/problems/two-sum/",
        "platform": "LeetCode",
        "difficulty": "Easy",
        "tags": ["Array", "Hash Table"],
        "solved_date": "2026-07-10",
        "languages": {
            "cpp": "solution.cpp",
            "python": "solution.py"
        },
        "code": {
            "cpp": """// Time Complexity: O(N)
// Space Complexity: O(N)
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};""",
            "python": """# Time Complexity: O(N)
# Space Complexity: O(N)

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        num_map = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_map:
                return [num_map[complement], i]
            num_map[num] = i
        return []"""
        },
        "description": "Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`."
    },
    {
        "id": "15",
        "title": "3Sum",
        "url": "https://leetcode.com/problems/3sum/",
        "platform": "LeetCode",
        "difficulty": "Medium",
        "tags": ["Array", "Two Pointers", "Sorting"],
        "solved_date": "2026-07-12",
        "languages": {
            "python": "solution.py"
        },
        "code": {
            "python": """# Time Complexity: O(N^2)
# Space Complexity: O(1) or O(N) depending on sorting implementation

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res = []
        nums.sort()
        
        for i, a in enumerate(nums):
            if i > 0 and a == nums[i - 1]:
                continue
                
            l, r = i + 1, len(nums) - 1
            while l < r:
                three_sum = a + nums[l] + nums[r]
                if three_sum > 0:
                    r -= 1
                elif three_sum < 0:
                    l += 1
                else:
                    res.append([a, nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res"""
        },
        "description": "Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`."
    },
    {
        "id": "42",
        "title": "Trapping Rain Water",
        "url": "https://leetcode.com/problems/trapping-rain-water/",
        "platform": "LeetCode",
        "difficulty": "Hard",
        "tags": ["Array", "Two Pointers", "Stack", "Dynamic Programming"],
        "solved_date": "2026-07-15",
        "languages": {
            "cpp": "solution.cpp"
        },
        "code": {
            "cpp": """// Time Complexity: O(N)
// Space Complexity: O(1)
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};"""
        },
        "description": "Given `n` non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining."
    },
    {
        "id": "",
        "title": "Subarray with given sum",
        "url": "https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1",
        "platform": "GeeksforGeeks",
        "difficulty": "Medium",
        "tags": ["Array", "Sliding Window"],
        "solved_date": "2026-07-14",
        "languages": {
            "java": "Solution.java"
        },
        "code": {
            "java": """// Time Complexity: O(N)
// Space Complexity: O(1)
import java.util.ArrayList;

class Solution {
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) {
        int start = 0;
        int currentSum = 0;
        ArrayList<Integer> res = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            currentSum += arr[i];
            
            while (currentSum > s && start < i) {
                currentSum -= arr[start];
                start++;
            }
            
            if (currentSum == s) {
                res.add(start + 1); // 1-based indexing
                res.add(i + 1);
                return res;
            }
        }
        res.add(-1);
        return res;
    }
}"""
        },
        "description": "Given an unsorted array `arr` of size `n` that contains only non-negative integers, find a continuous sub-array that adds to a given number `s` and return the 1-based indices of its start and end."
    },
    {
        "id": "",
        "title": "Missing number in array",
        "url": "https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1",
        "platform": "GeeksforGeeks",
        "difficulty": "Easy",
        "tags": ["Array", "Math"],
        "solved_date": "2026-07-11",
        "languages": {
            "python": "solution.py"
        },
        "code": {
            "python": """# Time Complexity: O(N)
# Space Complexity: O(1)

class Solution:
    def missingNumber(self, array, n):
        expected_sum = n * (n + 1) // 2
        actual_sum = sum(array)
        return expected_sum - actual_sum"""
        },
        "description": "Given an array of size `n-1` such that it only contains distinct integers in the range of `1` to `n`. Find the missing element."
    },
    {
        "id": "",
        "title": "Simple Array Sum",
        "url": "https://www.hackerrank.com/challenges/simple-array-sum/problem",
        "platform": "HackerRank",
        "difficulty": "Easy",
        "tags": ["Array", "Warmup"],
        "solved_date": "2026-07-09",
        "languages": {
            "javascript": "solution.js"
        },
        "code": {
            "javascript": """// Time Complexity: O(N)
// Space Complexity: O(1)

function simpleArraySum(ar) {
    return ar.reduce((sum, num) => sum + num, 0);
}"""
        },
        "description": "Given an array of integers, find the sum of its elements."
    }
]

def seed():
    print("Seeding repository with sample solutions...")
    
    for prob in SAMPLE_PROBLEMS:
        platform = prob["platform"]
        diff = prob["difficulty"]
        title = prob["title"]
        p_id = prob["id"]
        
        # Folder structure creation
        plat_dir = platform.lower().replace(" ", "")
        
        # Clean slug
        slug = title.strip().lower()
        slug = slug.replace(" ", "-").replace("/", "-")
        slug = "".join([c for c in slug if c.isalnum() or c == "-"])
        
        folder_name = f"{p_id}-{slug}" if p_id else slug
        prob_dir = os.path.join(REPO_DIR, plat_dir, diff, folder_name)
        os.makedirs(prob_dir, exist_ok=True)
        
        # Write metadata.json
        meta = {
            "id": p_id,
            "title": title,
            "url": prob["url"],
            "platform": platform,
            "difficulty": diff,
            "tags": prob["tags"],
            "solved_date": prob["solved_date"],
            "languages": list(prob["languages"].keys())
        }
        with open(os.path.join(prob_dir, "metadata.json"), "w", encoding="utf-8") as f:
            json.dump(meta, f, indent=2, ensure_ascii=False)
            
        # Write code files
        for lang, file_name in prob["languages"].items():
            code_content = prob["code"][lang]
            with open(os.path.join(prob_dir, file_name), "w", encoding="utf-8") as f:
                f.write(code_content)
                
        # Write README.md
        diff_badge = f"![Difficulty: {diff}](https://img.shields.io/badge/Difficulty-{diff}-"
        badge_colors = {"Easy": "green", "Medium": "yellow", "Hard": "red"}
        color = badge_colors.get(diff, "blue")
        diff_badge += f"{color}?style=flat-square)"
        
        readme_content = f"""# {title}

{diff_badge}
[![Platform: {platform}](https://img.shields.io/badge/Platform-{platform}-blue?style=flat-square)]({prob["url"]})

## 📝 Problem Description

{prob["description"]}

## 💡 Solution Approach

Implemented using optimal data structures and tracking state.

### Complexity Analysis

- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(N)$

---

## 💻 Code Implementations

"""
        for lang in prob["languages"].keys():
            lang_syntax = "cpp" if lang == "cpp" else ("python" if lang == "python" else ("java" if lang == "java" else "javascript"))
            readme_content += f"### {lang.upper()}\n\n"
            readme_content += f"``` {lang_syntax}\n// Refer to {prob['languages'][lang]} for the full implementation\n```\n\n"
            
        with open(os.path.join(prob_dir, "README.md"), "w", encoding="utf-8") as f:
            f.write(readme_content.strip() + "\n")
            
        print(f"Created sample solution: {platform} -> {title}")
        
    # Run sync script
    if os.path.exists(SYNC_SCRIPT):
        print("\nRunning sync_readme.py...")
        subprocess.run([sys.executable, SYNC_SCRIPT], cwd=REPO_DIR)
        print("Seeding complete!")
    else:
        print("sync_readme.py not found.")

if __name__ == "__main__":
    seed()
