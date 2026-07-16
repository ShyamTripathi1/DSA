class Solution {
public:
    int minOperations(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i =1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int sum = nums[i-1]+1-nums[i];
                nums[i] += sum;
                cnt += sum;
            }
        }
        return cnt;
    }
};
