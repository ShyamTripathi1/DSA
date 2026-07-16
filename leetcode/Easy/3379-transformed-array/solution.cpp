class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;;;;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int idx = (i+nums[i])%n;
                result.push_back(nums[idx]);
            }
            else if(nums[i]<0){
                int idx = (i+nums[i]%n+n)%n;
                result.push_back(nums[idx]);
            }
            else{
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
