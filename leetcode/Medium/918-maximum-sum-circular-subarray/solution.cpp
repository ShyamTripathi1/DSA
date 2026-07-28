class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minsum = nums[0];
        int maxsum = nums[0];
        int currmaxsum = nums[0];
        int currminsum = nums[0];
        int totalsum = nums[0];
        for(int i = 1;i<nums.size();i++){
            currmaxsum = max(currmaxsum + nums[i], nums[i]);
            maxsum = max(maxsum,currmaxsum);
            currminsum = min(currminsum + nums[i], nums[i]);
            minsum = min(minsum,currminsum);
            totalsum += nums[i];
        }
        int circularsum = totalsum - minsum;
        if( circularsum == 0){
            return maxsum;
        }
        return max(circularsum,maxsum);
    }
};
