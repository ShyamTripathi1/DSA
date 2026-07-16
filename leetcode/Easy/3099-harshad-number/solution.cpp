class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int count =0;
        int digit =x;
        while(digit>0){
            count+= digit % 10;
            digit/=10;
        }
        if ( x%count ==0) return count;
        else return -1;
    }
};
