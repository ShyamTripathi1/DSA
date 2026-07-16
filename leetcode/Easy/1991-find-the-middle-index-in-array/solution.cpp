class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
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
