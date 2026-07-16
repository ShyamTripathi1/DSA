class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int cnt=0;
        for (char x:s){
            if (s.count(x-'a'+'A')){
                cnt++;
            }
        }

        return cnt;
    }
};
