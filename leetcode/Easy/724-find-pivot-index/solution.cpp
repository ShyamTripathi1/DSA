class Solution {
public:
      int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        int count =0;
        for(int i=0;i<n;i++){
            count += nums[i];
        }
        int sum =0;
        for(int i=0;i<n;i++){
            count -= nums[i];
            if(count == sum){
                return i;
            }
             sum += nums[i];
        }
        return -1;

    }
};
