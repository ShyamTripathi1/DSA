class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        sort(nums.begin(),nums.end());
        int res = nums[n-1]-nums[0];
        for(int i =0;i<n-1;i++){
            int maxi = nums[n-1]-k;
            int mini = nums[0]+k ;
            res = min(res,maxi-mini);
        }
         return max(0,res); 
    }
};
