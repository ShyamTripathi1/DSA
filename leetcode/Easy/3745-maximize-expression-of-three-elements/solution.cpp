class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result = 0;
        int n = nums.size();
        result += nums[n-2]+nums[n-1]-nums[0];
        return result;
    }
};
