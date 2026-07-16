class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n /= 10;
        }
        reverse(digits.begin(),digits.end());
        int sum =0;
        int sum1 =0;
        for(int i=0;i<digits.size();i++){
            if(i%2==0){
                sum1 += digits[i];

            }
            else{
                sum += (-1)*digits[i];
            }
        }
        return sum1 + sum;
        
    }
};
