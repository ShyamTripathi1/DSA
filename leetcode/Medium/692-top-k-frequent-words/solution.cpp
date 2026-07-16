class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string &s:words){
            mp[s]++;
        }
        priority_queue<pair<int,string>>pq;
        for(auto &it:mp){
            pq.push({-it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        for(int i =0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
