class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int sum1 = 0;
        for(int i =0;i<n;i++){
         if(i%2==0){
            sum += nums[i];
         }
         else{
            sum1 += nums[i];
         }
        }
        return sum-sum1;
    }
};
