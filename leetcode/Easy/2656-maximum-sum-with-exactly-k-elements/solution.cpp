class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum =0;
        int m = nums[n-1];
        while(k--){
            sum += m;
            m++;
        }
 return sum;
        
    }
};
