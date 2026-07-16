class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            if (isupper(word[i])) {
                capitalCount++;
            }
        }

        // Case 1: All letters are uppercase
        if (capitalCount == n) return true;

        // Case 2: All letters are lowercase
        if (capitalCount == 0) return true;

        // Case 3: Only the first letter is uppercase
        if (capitalCount == 1 && isupper(word[0])) return true;

        // Otherwise, not correct capital usage
        return false;
    }
};


