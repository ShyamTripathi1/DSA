class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int multiple = k;
        for (int i = 0; i < n; i++) {
            if (nums[i] == multiple) {
                multiple += k;
            } else if (nums[i] > multiple) {
                return multiple;
            }
        }
        return multiple;
    }
};

