class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int ele:nums){
            sum ^= ele;
        }
    return sum;
    }
};
