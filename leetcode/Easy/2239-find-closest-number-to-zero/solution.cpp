class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int close = INT_MAX,ans;
        for(int i =0;i<n;i++){
            if(abs(nums[i] <= close)){
            close = abs(nums[i]);
            ans = nums[i];
            }
        }
        return ans;
    }
};
