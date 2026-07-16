class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int ele: nums){
            mp[ele]++;
        }
        sort(nums.begin(),nums.end(), [&] (int a, int b){
        if(mp[a]== mp[b])
            return a>b;
            return mp[a]<mp[b];
        });
        return nums; 
    }
};
