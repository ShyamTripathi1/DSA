class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        //if(n==1) return 0;
        int maxi =0;
        sort(nums.begin(),nums.end());
        int left = 0;
        for(int right=0;right<n;right++){
            while((long long)nums[left]*k <nums[right]){
                left++;
            }
                 maxi = max(maxi,right-left+1);
        }
        return n-maxi;
    }
};
