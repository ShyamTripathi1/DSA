class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq,freqcount;
        for(int ele:nums){
            freq[ele]++;
        }
        for(auto it:freq){
            freqcount[it.second]++;
        }
        for(int i =0;i<n;i++){
            if(freqcount[freq[nums[i]]] == 1)
            return nums[i];
        }
       return -1;
    }
};
