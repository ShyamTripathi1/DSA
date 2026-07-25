class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
      while(num>0){
        int d = num%10;
        num /= 10;
         ans += d;

      }  
      if(ans < 10) return ans;
      else return addDigits(ans);
    }
};
