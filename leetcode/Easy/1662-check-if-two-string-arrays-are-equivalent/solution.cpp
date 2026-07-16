class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        string s1;
        string s2;
        for(int i =0;i<n;i++){
            s1+= word1[i];
        }
        for(int j =0;j<m;j++){
            s2+= word2[j];
        }
        return s1 == s2;
        
    }
};
