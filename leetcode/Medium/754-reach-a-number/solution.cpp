class Solution {
public:
    int reachNumber(int target) {
        int steps = 0;
        int sum = 0;
        target = abs(target);
        while(true){
            steps++;
            sum = sum+steps;
            if((sum>= target) && (sum-target)%2 == 0 ){
                return steps;
            }
        }
        return -1;
    }
};
