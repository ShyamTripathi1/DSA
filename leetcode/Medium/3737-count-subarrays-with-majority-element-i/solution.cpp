class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            int tgt = 0;
            for(int j = i;j<n;j++){
                if(nums[j] == target){
                    tgt++;
                }
                int len = j-i+1;
            
            if(tgt >len/2){
                ans++;
            }
        }
        }
        return ans;
    }
};
