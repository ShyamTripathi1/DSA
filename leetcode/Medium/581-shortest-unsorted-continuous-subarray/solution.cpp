class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ans= nums;
        sort(ans.begin(),ans.end());
        int n = nums.size();
        int i =0;
        int j = n-1;
        
        while(i <n && nums[i]==ans[i]){
            i++;
        }
        while(j>i && nums[j]==ans[j]){
            j--;
        }
        if( i >= j){
            return 0;
        }
        return j-i+1;
    }
};
