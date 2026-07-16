class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum = 0;
        int sum1 = 0;
        for(int i= n-1;i>= n-k;i--){
            sum += nums[i];
        }
        for(int i = 0;i<k;i++){
            sum1 += nums[i];
        }
        return sum-sum1;
    }
};
