class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt =0;
        int n = nums.size();
        int totalsum =0;
        for(int i =0;i<n;i++){
            totalsum += nums[i];
        }
        int l=0;
        int r=0;
        for(int i =0;i<n-1;i++){
            l += nums[i];
            r = totalsum - l;
            if((l%2 == 0) == (r%2 == 0)){
                cnt++;
            }
        }
        return cnt;
    }
};
