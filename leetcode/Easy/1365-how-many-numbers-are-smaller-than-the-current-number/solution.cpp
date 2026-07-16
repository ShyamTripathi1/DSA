class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        //int count=0;
        //sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(j!= i && nums[j]<nums[i]){
                    count++;
                   // ans.push_back(count);
                }

            }
            ans.push_back(count);
        }
        return ans;
        
    }
};
