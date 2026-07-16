class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        int sum =0;
        for(int i=0;i<n;i++){
            cnt += nums[i];
            int digit = nums[i];
            while(digit>0){
            sum += digit%10;
            digit/= 10;
         }
        }
        return abs(cnt-sum);
    }
};
