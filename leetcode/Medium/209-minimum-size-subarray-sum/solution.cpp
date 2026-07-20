class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size();
      int res = INT_MAX;
      int sum = 0;
      int low = 0;
      int high = 0;
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
