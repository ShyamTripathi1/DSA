class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_map<double,int> a;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()/2;i++){
            a[(nums[i]+nums[nums.size()-1-i])/2.0]++;
        }
        return a.size();
    }
};
