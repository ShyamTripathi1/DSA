class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int m = brokenLetters.size();
        int cnt =0;
        int ans=0;
        for(int i =0;i<n;i++){
            bool ok = true;
            while(i<n && text[i] != ' '){
            for(int j=0;j<m;j++){
                if(text[i] == brokenLetters[j]){
                    ok = false;
                    break;
                }
                }
                i++;
        }
            if(ok) ans++;
        }
        return ans;
        
    }
};
