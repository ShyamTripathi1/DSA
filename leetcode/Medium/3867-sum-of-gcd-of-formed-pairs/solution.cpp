#include <numeric>

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi,nums[i]);
            prefixGcd[i] = gcd(nums[i],maxi);
        }
        long long ans = 0;
        sort(prefixGcd.begin(), prefixGcd.end());
        int w = prefixGcd.size();
       int l=0,h=w-1;
       while(l<h){
        ans += gcd(prefixGcd[l],prefixGcd[h]);
        l++;
        h--;
       }

        return ans;
    }
};
