class Solution {
public:
    string sortedStr(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
    
    bool reorderedPowerOf2(int n) {
        string original = sortedStr(n);
        
        // Check all powers of two up to 10^9
        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            if (sortedStr(power) == original) {
                return true;
            }
        }
        return false;
    }
};

