class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
         if (n ==0) return -1;
         if (n ==1) return 0;
        vector<int>original = nums;
        sort(nums.begin(),nums.end());
        int maxi = nums[n-1];
        for(int i =0;i<n-1;i++){
            if(maxi < 2*nums[i]){
                return -1;
            }
        }
        for(int i =0;i<n;i++){
            if(original[i] == maxi){
                return i;
            }
        }
        return -1;
    }
};
