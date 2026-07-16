class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int length = s.size();
        long long sum = 0;
        int temp, letterNum;

        for (int i = length - 1; i >= 0; i--) {
            sum += shifts[i];
            temp = sum % 26;
            letterNum = s[i] - 'a';
            letterNum = (letterNum + temp) % 26;
            s[i] = 'a' + letterNum;
        }

        return s;
    }
};
