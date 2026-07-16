class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int n = nums.size();
     unordered_map<int,int>mp;
      for(int ele:nums){
        mp[ele]++;
      }
      int ans = 0;
      for(auto it : mp)   {
        if(it.second>n/2){
            ans += it.first;
        }
      }
      return ans;
    }
};
