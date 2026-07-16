class Solution {
public:
    int minElement(vector<int>& nums) {
      int maxi = INT_MAX;
      int n = nums.size();
      for(int num:nums){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        maxi = min(maxi, sum);
      }
      return maxi;
    }
};
