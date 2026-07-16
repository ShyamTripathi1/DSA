class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        vector<string> result;
        
        // Process s1
        stringstream ss1(s1);
        string word;
        while (ss1 >> word) {
            freq[word]++;
        }
        
        // Process s2
        stringstream ss2(s2);
        while (ss2 >> word) {
            freq[word]++;
        }
        
        // Collect words with frequency 1
        for (auto& p : freq) {
            if (p.second == 1) {
                result.push_back(p.first);
            }
        }
        
        return result;
    }
};
