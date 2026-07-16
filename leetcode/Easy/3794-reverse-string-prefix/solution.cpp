class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();
        string p;
        string q;
        for(int i=k-1;i>=0;i--){
          p += s[i];  
        }
        for(int i=k;i<n;i++){
            q += s[i];
        }
        return p+q;
    }
};
