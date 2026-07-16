class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int>m;
       int maximum = 0;
       int sum =0;
       for(int element:nums){
        m[element]++;
        maximum = max(maximum,m[element]);
       }
       for(auto &it:m){
        if(it.second == maximum){
            sum += maximum;
        }
       }
       return sum;
    }

};
