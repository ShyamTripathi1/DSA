class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *min_element(nums.begin(),nums.end());
        int cnt = 0;
        for(int i : nums){
            cnt +=  i-maxi;
        }
        return cnt;
        
    }
};
