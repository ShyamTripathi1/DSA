class Solution {
public:
    int rob(vector<int>& nums) {
        int  a = 0;
        int b = 0;
        for(int ele:nums){
            int k = max(b, a+ele);
            a = b;
            b = k;
        }
        return b;
    }
};
