class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>ans1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans.push_back(nums[i]);
            }
            else{
                ans1.push_back(nums[i]);

            }
        }
        for(int i = 0; i < ans1.size(); i++) {
            ans.push_back(ans1[i]);
        }
        return ans;

        
    }
};
