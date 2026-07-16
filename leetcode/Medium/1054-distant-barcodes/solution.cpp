class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pq; 
    for(int x : barcodes) {
        mp[x]++;
    }
    for(auto &it : mp) {
        pq.push({it.second, it.first});
    }
    vector<int> res;
    while(pq.size() > 1) {
        auto p1 = pq.top(); pq.pop();
        auto p2 = pq.top(); pq.pop();
        res.push_back(p1.second);
        res.push_back(p2.second);
        p1.first--;
        p2.first--;
        if(p1.first > 0) pq.push(p1);
        if(p2.first > 0) pq.push(p2);
    }
    if(!pq.empty()) {
        res.push_back(pq.top().second);
    }
    return res;
    }
};
