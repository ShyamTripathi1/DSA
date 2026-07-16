class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string s ="";
        for(int i =0;i<words.size();i++){
            string c = words[i];
            reverse(words[i].begin(),words[i].end());
            if(words[i] == c) return c;
        }
        return s;
    }
};
