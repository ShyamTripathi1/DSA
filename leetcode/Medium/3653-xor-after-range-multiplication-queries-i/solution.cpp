class Solution {
public:
int M = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      for(auto q:queries){
        int l = q[0];
        int r = q[1];
        int k = q[2];
        int v = q[3];
        while(l<= r){
             nums[l] = (1LL* nums[l]*v)%M;
            l += k;
        }
      }
      int result = 0;
      for(int ele:nums){
        result ^= ele;
      }
     return result;
    }
};
