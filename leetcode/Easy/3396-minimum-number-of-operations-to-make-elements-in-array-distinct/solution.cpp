class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        // Traverse from back to front
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    // Found duplicate — need to remove [0..i]
                    return (i + 3) / 3; // ceil((i+1)/3)
                }
            }
        }

        // No duplicates found
        return 0;
    }
};

