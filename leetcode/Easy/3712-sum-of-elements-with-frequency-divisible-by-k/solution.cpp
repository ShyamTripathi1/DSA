class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum =0;
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        for(const auto &pair:mp){
            if(pair.second % k ==0){
                sum += pair.first * pair.second;
            }
        }
        
        return sum;
    }
};
