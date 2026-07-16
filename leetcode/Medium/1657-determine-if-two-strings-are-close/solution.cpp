class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mp;
        for(char ele: word1){
            mp[ele]++;
        }
        unordered_map<char,int> mp1;
        for(char ele : word2){
            mp1[ele]++;
        }
        vector<int> ans;
        vector<int> ans1;
        for(const auto& pair : mp){
            ans.push_back(pair.second);
        }
        for(const auto& pair:mp1){
            ans1.push_back(pair.second); 
        }
        // Check if both strings have the same set of characters
        if (mp.size() != mp1.size()) return false;
        for (const auto& p : mp) {
            if (mp1.find(p.first) == mp1.end()) return false;
        }
        // Sort frequency vectors
        sort(ans.begin(), ans.end());
        sort(ans1.begin(), ans1.end());
        // Compare sorted frequencies
        return ans == ans1;
    }
};

