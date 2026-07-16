class Solution {
public:
    int countKeyChanges(string s) {
        int cnt =0;
        for(int i =0;i<s.size();i++){
            s[i] = tolower(s[i]);
        }
        for(int j =0;j<s.size()-1;j++){
            if(s[j] != s[j+1]){
            cnt++;
            }
        }
        return cnt;
    }
};
