class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int low = 0, high = 0;
      int res = INT_MAX;
      int sum = 0;
      int n = nums.size();
      while(high<n){
        sum += nums[high];
        while(sum >= target){
            int len = high-low+1;
            res = min(res,len);
            sum -= nums[low];
            low++;
        }
        high++;
      }  
      return (res == INT_MAX) ? 0 : res;
    }
};
