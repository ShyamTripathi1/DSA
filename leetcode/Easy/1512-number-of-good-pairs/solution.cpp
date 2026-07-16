class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count =0;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(i<j && nums[i]== nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
