class Solution {
public:
    int arraySign(vector<int>& nums) {
        int digit =1;
        for(int i=0;i<nums.size();i++){
           if(nums[i] == 0) return 0;
           if(nums[i]<0) digit *= -1;
        }
        if(digit>0){
            return 1;
        }
        else{
            return -1;
        }
        
        
    }
};
