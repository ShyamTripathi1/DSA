class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int a=pow(2,31)-1;
        for(int i =1;i<=a;i++){
            if(s.find(i) == s.end() ){
                return i;
            }
        }
        return a;
        
    }
};
