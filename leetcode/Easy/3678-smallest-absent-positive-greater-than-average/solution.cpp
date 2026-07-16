class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        double avg = sum/n;
        int ans = (int)floor(avg) + 1;
        if(ans<=0){
             ans = 1;
        }
        for(int i=0;i<n;i++){
            if(ans == nums[i]){
                ans++;
            }
        }
        return ans;
    }
};
