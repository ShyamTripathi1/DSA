class Solution {
public:
    string majorityFrequencyGroup(string s) {
       unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        unordered_map<int, vector<char>> groups;
           int maxfreq = 0;
        for(auto &p : freq){
            groups[p.second].push_back(p.first);
            maxfreq = max(maxfreq,p.second);
        }
        int bestfreq=0,bestsize=0;
        for(auto &g : groups){
            int k = g.first;
            int sz = g.second.size();
            if(sz>bestsize || (sz == bestsize && k > bestfreq)){
                bestsize = sz;
                bestfreq = k;
            }
        }
        string result;
        for( char c: groups[bestfreq]){
            result.push_back(c);
        }
        
        return result;
    }
};
