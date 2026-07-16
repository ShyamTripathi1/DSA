class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();
        int maximum =0;
        int maxi =0;
        int vowelFreq[26] ={0};
        int consonantFreq[26] = {0};


        for (int i = 0; i < n; i++) {
            if(s[i]>='a' && s[i]<='z'){
             if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                vowelFreq[s[i]-'a']++;
                maximum = max(maximum,vowelFreq[s[i]-'a']);
            }
            else{
                consonantFreq[s[i]-'a']++;
                maxi = max(maxi,consonantFreq[s[i]-'a']);


            }
            }
        }
        return maximum + maxi;
    }
};

