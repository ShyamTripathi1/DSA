class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int>mp;
        int i =0;
        for(i=nums.size()-1;i>=0;i--){
            if(mp.count(nums[i])) break;
            mp.insert(nums[i]);
        }
        return (i+3)/3;
    }
};
