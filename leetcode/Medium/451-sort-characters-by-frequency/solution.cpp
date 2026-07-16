class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int ele: s){
            mp[ele]++;
        }
        priority_queue<pair<int,char>> maxHeap;
        for(const auto& entry : mp){
            maxHeap.push({entry.second,entry.first});
        }
        string res;
        while(!maxHeap.empty()){
            auto[val,key] = maxHeap.top();
            maxHeap.pop();
            res.append(val,key);
        }
        return res;
    }
};
