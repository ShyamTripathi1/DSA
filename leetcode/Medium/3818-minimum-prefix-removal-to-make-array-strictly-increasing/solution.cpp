class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i-1]>=nums[i]) return i;

        }
        return 0;
    }
};
