class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto it:words){
            if(it.size() >= k){
                string p = it.substr(0,k);
            mp[p]++;
        }
        }
        int ans = 0;
        for(auto it:mp){
            if(it.second >= 2) ans++;
        }
       return ans; 
    }
};
