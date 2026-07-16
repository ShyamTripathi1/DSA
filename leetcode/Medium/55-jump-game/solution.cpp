class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i =0;i<n;i++){
            if(i>count) return false;
            count=max(count,i+nums[i]);
           // return true;
           
            
        }

      return true;  
    }
};
