class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(string word:words){
        if(word.size() != pattern.size()) continue;
        unordered_map<char,char>mp1,mp2;
        bool ok = true;
        for(int i =0;i<word.size();i++){
            char x = word[i];
            char y = pattern[i];
            if((mp1.count(x) && mp1[x] != y)||(mp2.count(y) && mp2[y] != x)){
                ok = false;
                break;
            }
            mp1[x]= y;
            mp2[y] = x;
        }
        if (ok)ans.push_back(word);
        }
        return ans;
    }
};
