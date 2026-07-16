class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
        if(i==nums.size()-1 || nums[i]!=nums[i+1]){
             ans.push_back(nums[i]);
        }
        }
          if(ans.size()<3){
            return ans[ans.size()-1];
        }
        
        
        return ans[ans.size()-3];
        
    }
};

