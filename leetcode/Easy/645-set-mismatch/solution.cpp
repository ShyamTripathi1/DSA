class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        int smallest =1;
        for(int i =0;i<n;i++){
            if(i<n-1 && nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
            }
            else if(nums[i] == smallest){
              smallest++;
            }
           
               
        }
        ans.push_back(smallest);
        return ans;

        
    }
};
