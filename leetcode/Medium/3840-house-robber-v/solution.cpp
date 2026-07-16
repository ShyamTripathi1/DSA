class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long ans=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            int j=i;
            while(j<n && colors[j]==colors[i]) j++;
            long long prev1=0,prev2=0;
            for(int k=i;k<j;k++){
                long long temp=max(prev1,prev2+nums[k]);
                prev2=prev1;
                prev1=temp;
            }
            ans+=prev1;
            i=j;
        }
        return ans;
    }
};

