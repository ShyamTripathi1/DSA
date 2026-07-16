class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        //int minimum = *min(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i % 10 == nums[i]){
               // minimum = (minimum,nums[i]);
                return i;
            }
        }
        return -1;
    }
};
