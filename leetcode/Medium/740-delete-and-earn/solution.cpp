class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int max_num = 0;
        for(int i=0; i < nums.size(); i++){
            max_num = max(max_num, nums[i]);
        }
        vector<int> dp(max_num + 4, 0);
        for(int i=0; i < nums.size(); i++){
            dp[nums[i]] += nums[i];
        }
        for(int i=max_num; i > -1; i--){
            dp[i] += max(dp[i + 2], dp[i + 3]);
        }
        return max({dp[0], dp[1]});
    }
};
