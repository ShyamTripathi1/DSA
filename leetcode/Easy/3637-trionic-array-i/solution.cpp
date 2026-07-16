class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p =-1;
        int q=-1;
        if(n<3) return false;
       
        for(int i =0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                p=i;
               
            }
            else  break;
        }
                if(p<0) return false;
            
                for(int j=p+1;j<n-1;j++){
                    if(nums[j]>nums[j+1]){
                        q=j;
                       
                    }
                    else  break;
                }
                if(p>=q) return false;
                        if(q==n-2) return false;
                    
                    for(int k=q+1;k<n-1;k++){
                         if (nums[k] < nums[k + 1]) continue; 
               else return false;
        }
        return true;
        
    }
};
