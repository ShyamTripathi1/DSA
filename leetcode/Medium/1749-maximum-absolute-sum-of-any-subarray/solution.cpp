class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
    int bestending = nums[0], bestending1 = nums[0],res = nums[0], res1 = nums[0];
    for(int i = 1;i<nums.size();i++){
        int v1 = nums[i];
        int v2 = nums[i]+bestending;
        int v3 = nums[i] + bestending1;
        bestending = max(v1,v2);
        bestending1 = min(v1,v3);
        res = max(res,bestending);
        res1 = min(res1,bestending1);
    }  
    int ans = abs(res);
    int ans1 = abs(res1);
    return max(ans,ans1);
    }
};
