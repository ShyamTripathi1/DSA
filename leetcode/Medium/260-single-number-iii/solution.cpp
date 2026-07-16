class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int ele:nums){
            mp[ele]++;
        }
        vector<int>ans;
        for(const auto& pair:mp){
            if(pair.second == 1){
                ans.push_back(pair.first);
            }
        }
     return ans;  
    }
};
