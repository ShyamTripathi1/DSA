class Solution {
public:
    int fnc(vector<int>& nums){
       int a = 0;
       int b = 0;
       for(int ele : nums){
            int k = max(b, a + ele);
            a = b;
            b = k;
       }
       return b;
       //return b;
        
    }
    int rob(vector<int>& nums) {
         int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> a(nums.begin(), nums.end()-1);
        vector<int> b(nums.begin()+1, nums.end());

          int case1 = fnc(a);
        int case2 = fnc(b);

        return max(case1, case2);
    }
};
