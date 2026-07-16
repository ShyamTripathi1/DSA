class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int smallest = mini;
        vector<int> ans;
        int j =0;
        for(int i = mini;i<maxi;i++){
            if( j< n && nums[j] == i ){
                j++;
               
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};
