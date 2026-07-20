class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int i = 0,j=1;
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(),nums.end());
        while(j<n){
           
            if(i == j){ 
            j++;
            continue;
            }
             int diff = abs(nums[i]-nums[j]);
            if(diff == k){
                 cnt++;
                 i++;
                 j++;
            

            while(i < n && nums[i] == nums[i-1])
                i++;
            while(j < n && nums[j] == nums[j-1])
                j++;
            
            continue;
            }
            
           if(diff <k){
            j++;
           }
           else {
            i++;
           }
            }

        
        return cnt;
    }
};
