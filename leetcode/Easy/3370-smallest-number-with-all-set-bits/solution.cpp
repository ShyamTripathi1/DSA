class Solution {
public:
    int smallestNumber(int n) {
        int x1 = (log(n))/(log(2));
        x1++;
        return pow(2,x1)-1;
        
    }
};
