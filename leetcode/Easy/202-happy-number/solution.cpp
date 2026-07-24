class Solution {
public:
int fnc(int n ){
    int sum = 0;
    while(n>0){
        int d = n% 10;
        n /= 10;
        sum += d*d;
    }
    return sum;
}
    bool isHappy(int n) {
        int slow = n, fast = n;
        while( fast != 1){
            slow = fnc(slow);
            fast = fnc(fast);
            fast = fnc(fast);
            if(slow == fast && slow != 1){
                return false;
            }
        }
        return true;
        
    }
};
