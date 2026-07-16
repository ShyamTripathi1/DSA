class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> freq;
        // Count each digit's frequency
        for (char c : s) {
            freq[c]++;
        }
        // Check adjacent pairs
        for (int i = 0; i < s.size() - 1; i++) {
            char a = s[i], b = s[i + 1];
            if (a != b && freq[a] == (a - '0') && freq[b] == (b - '0')) {
                return {a, b};
            }
        }
        return "";
    }
};

