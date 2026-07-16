class Solution {
public:
    int countEven(int num) {
        int cnt =0;
        for(int i=2;i<=num;i++){
            int ans =0;
            int temp =i;
            while(temp>0){
            int digit = temp%10;
            ans+= digit;
            temp/=10;
        }
        if(ans%2 ==0){
            cnt++;
        }
        }
        return cnt;
    }
};
