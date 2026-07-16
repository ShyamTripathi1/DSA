class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < ransomNote.size(); i++) {
            bool found = false;
            for (int j = 0; j < magazine.size(); j++) {
                if (ransomNote[i] == magazine[j]) {
                    magazine[j] = '#';  // Mark this character as used
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;  // character not found in magazine
            }
        }
        return true;
    }
};

