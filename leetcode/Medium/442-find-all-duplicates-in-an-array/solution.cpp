class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      unordered_map<int,int>mp;
      for(int ele:nums){
        mp[ele]++;
      }
      vector<int>ans;
      for(auto it:mp){
        if(it.second>=2){
            ans.push_back(it.first);
        }
      }
      return ans;
    }
};
