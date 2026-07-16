class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long count =0;
        long ans =0;
        for(int i =0;i<n;i++){
            if(nums[i]==0){
                count =0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    count++;
                    
                }
                else{
                    break;
                }
            }
                ans=ans+count*(count+1)/2;
                   i = i + count - 1;
            }
            
        }
       return ans; 
    }
};
