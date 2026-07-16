class Solution {
public:
    int countBinarySubstrings(string s) {
      int result = 0;
      int prevcount = 0;
      int currcount = 1;
      for(int i =1;i<s.length();i++){
        if(s[i] == s[i-1]){
            currcount++;
        }
        else{
            result += min(prevcount,currcount);
            prevcount = currcount;
            currcount = 1;
        }

      }  
      return result+min(prevcount,currcount);
    }
};
