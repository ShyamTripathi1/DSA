class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int ans = nums[0], res = nums[0];
     for(int i = 1;i<nums.size();i++){
        int v1 = ans +nums[i];
        int v2 = nums[i];
        ans = max(v1,v2);
        res = max(ans, res);
     } 
     return res;  
    }
};
