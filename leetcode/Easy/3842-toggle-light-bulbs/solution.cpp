class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int>mp;
        for(int ele:bulbs){
            mp[ele]++;
        }
        vector<int>ans;
        for(auto &it :mp){
            if(it.second %2 == 1){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
