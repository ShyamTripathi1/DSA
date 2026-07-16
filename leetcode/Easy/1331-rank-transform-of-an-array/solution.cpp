class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      int n = arr.size();
      set<int> st(arr.begin(),arr.end());
      int rank = 1;
      unordered_map<int,int>mp;
      for(int ele:st){
        mp[ele] = rank++;
      }
      vector<int> ans;
      for(int ele:arr){
        ans.push_back(mp[ele]);
      }
      return ans;
    }
};
