class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
       int maximum;
       int maximum2;

            maximum = nums[n-2];
            maximum2 = nums[n-1];
        
        return ((maximum-1)*(maximum2-1));

        
    }
};
