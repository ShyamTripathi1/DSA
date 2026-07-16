class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ans(26, 0); 
        for (char ch : s) {
            ans[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (ans[s[i] - 'a'] == 1)
                return i;
        }
        return -1; 
    }
};

