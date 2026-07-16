class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum = 0;
        int sum1 = 0;
        while(n>0){
            int res = n%10;
            n /= 10;
         sum += res;
         sum1 += res*res;
        }

        return sum1 - sum >= 50;
    }
};
