class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a =0,b=0;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(s[i] == 'a'){
                a++;
            }
            else{
                b++;
            }
        }
       return abs(a-b); 
    }
};
