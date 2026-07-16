class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        //sort(nums.begin(),nums.end());
        int count =0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count += nums[i-1]*nums[i-1];
            }
        }
        return count;
    }
};
