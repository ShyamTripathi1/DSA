class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        if (n==1) return 1;
        while(i<=n){
            n=n-i;
            i++;
        }
        
       return i-1; 
    }
};
