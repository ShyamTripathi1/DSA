class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
       // int count = 1;
        for (int i = 0; i < n; i++) { 
            if((i==0 || nums[i]!=nums[i-1]) && (i==n-1 ||nums[i]!=nums[i+1])) {
                sum+=nums[i];
            }

        }
        return sum;
    }
};

