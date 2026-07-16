class Solution {
    public int pivotIndex(int[] nums) {
        int total_sum = 0;
        for(int i : nums){
            total_sum += i;
        }
        int sum = 0;
        for(int i = 0; i<nums.length;i++){
            total_sum -= nums[i];
            sum += nums[i];

            if(total_sum == sum - nums[i]){
                return i;
            }
        }
        return -1;
    }
}
