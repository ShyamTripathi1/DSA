class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        int result = 0;
        for(int i=2;i<=n-1;i++){
            result = cost[i] + min(a,b);
            a = b;
            b = result;
        }
        return min(a,b);
    }
};
