class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        for(int i =0;i<n;i++){
            maximum = max(maximum,nums[i]);
        }
        for(int j =0;j<n;j++){
            minimum = min(minimum,nums[j]);
        }
        for(int k =0;k<n;k++){
            if(nums[k]!= maximum && nums[k]!= minimum)
            return nums[k];
        }
        return -1;
        
    }
};
