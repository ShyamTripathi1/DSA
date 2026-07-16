class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g= nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            g = gcd(g,nums[i]);
            if(g==1) return true;

        }
        return false;
    }
};
