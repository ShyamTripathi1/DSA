class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    int ans = nums[i] ^ nums[j];
                    maximum = max(maximum, ans);
                }
            }
        }
        return maximum;
    }
};
