class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int maximum = -1;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(nums[i]== -nums[j]){
                    maximum = max(maximum,abs(nums[i]));
                }
    
            }
        }
        return maximum;
        
    }
};
