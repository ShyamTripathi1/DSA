class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int val = 0;
        vector<bool>ans;
        for(auto& ele:nums){
           val = ((val<<1)+ele)%5;
           ans.push_back(val == 0);
        }
       return ans; 
    }
};
