class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int sum =0;
        for(int i=0;i<n;i++){
            if(nums[i]%10 == nums[i]) sum += nums[i];
            else if(nums[i]%10 != nums[i]) count += nums[i]; 

        }
        return count != sum;
        
    }
};
