class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int it : nums){
            maxi = max(it,maxi);
            mini = min(it,mini);

        }
        return 1L*k*(maxi-mini);
    }
};
