class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maximum =0;
        for(int i=0;i<n-1;i++)
        maximum = max(maximum,abs(nums[i+1]-nums[i])); 
        maximum = max(maximum, abs(nums[n-1] - nums[0]));
        return maximum;
    }
};
