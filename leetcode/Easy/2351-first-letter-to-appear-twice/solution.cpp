class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        for (int j = 0; j < n; ++j) {        // position of the possible 2nd appearance
            for (int i = 0; i < j; ++i) {    // check any earlier same char
                if (s[i] == s[j]) {
                    return s[j];             // earliest second occurrence
                }
            }
        }
        return ' '; // per constraints, shouldn't reach here
    }
};

