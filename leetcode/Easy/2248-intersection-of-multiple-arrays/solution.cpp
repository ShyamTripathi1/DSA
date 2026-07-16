class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<nums[i].size();j++)
            {
                mp[nums[i][j]]++;
            }
        }
        for(const auto& pair:mp){
            if(pair.second == n){
                ans.push_back(pair.first);
            }
        }
         sort(ans.begin(),ans.end());
         return ans;

    }
};
