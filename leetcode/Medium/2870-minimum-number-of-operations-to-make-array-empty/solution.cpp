class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int ele:nums){
            mp[ele]++;
        }
        int cnt = 0;
        for(const auto& pair :mp){
            if(pair.second == 1) return -1;
            else {
                cnt += (pair.second+2)/3;
            }
        }
        return cnt;
    }
};
