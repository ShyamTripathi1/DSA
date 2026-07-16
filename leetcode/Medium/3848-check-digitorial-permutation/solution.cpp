class Solution {
public:
   
  

    
    bool isDigitorialPermutation(int n) {
        vector<int>p{1,1,2,6,24,120,720,5040,40320,362880};
        int x = n; int fact = 0;  
        while( x > 0){
            int d = x % 10;
            fact += p[d];
            x /= 10;
        }
        vector<int>freq(10,0);
        x = n;
        while( x > 0){
            freq[x%10]++;
            x /=10;
        }
        vector<int>freq2(10,0);
        x = fact;
        while( x > 0){
            freq2[x%10]++;
            x /=10;
        }
        if(freq2[0] > freq[0]) return false;

        return freq == freq2;
         
    }
};
