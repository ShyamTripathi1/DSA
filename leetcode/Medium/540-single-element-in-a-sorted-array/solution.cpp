class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int ele:nums){
            mp[ele]++;
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second == 1) {
                ans += it.first;
            }
        }
        return ans;
    }
};
