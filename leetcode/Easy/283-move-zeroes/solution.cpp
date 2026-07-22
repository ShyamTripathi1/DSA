class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int low = 0, high = 0;
      int n = nums.size();
      while(high<n){
        if(nums[high] != 0){
            swap(nums[low],nums[high]);
            low++;

        }
        high++;
      }  
    }
};
