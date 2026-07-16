class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int n = nums.size();
        for(int i =1;i<n;i++){
           if(nums[i] <= nums[i-1]){
            int sum = nums[i-1]+1-nums[i];
            nums[i] += sum;
            cnt += sum;
           }
           }
           return cnt;
    }
};
