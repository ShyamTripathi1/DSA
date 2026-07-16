class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
       unordered_map<char,long long>mp;
        for(int i =0;i<s.length();i++){
            mp[s[i]] += cost[i];
        }
            vector<pair<long long,char>> ans;
            for(auto it:mp){
                ans.push_back({it.second,it.first});
            }
            sort(ans.begin(),ans.end());
            int n = ans.size();
            long long final = 0;
            for(int i=0;i<n-1;i++){
                final += ans[i].first;
            }
        
        return final;
    }
};
