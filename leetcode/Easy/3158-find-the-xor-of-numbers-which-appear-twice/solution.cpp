class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int ele:nums){
            mp[ele]++;
        }
        int ans =0;
        for(const auto& pair: mp){
            if(pair.second == 2){
                ans ^= pair.first;
            }
        }
        return ans;
    }
};
