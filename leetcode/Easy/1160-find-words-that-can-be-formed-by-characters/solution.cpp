class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for (char ele : chars) {
            mp[ele]++;
        }
        
        int result = 0;
        for (string word : words) {
            unordered_map<char, int> mp1;
            for (char c : word) {
                mp1[c]++;
            }
            
            bool canForm = true;
            for (auto& p : mp1) {
                if (mp[p.first] < p.second) { // Compare with mp, not mp1
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                result += word.size();
            }
        }
        return result;
    }
};

