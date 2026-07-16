class Solution {
    int lis(vector<int>& nums){
        vector<int> lis;
        for(int x:nums){
            auto it = lower_bound(lis.begin(),lis.end(),x);
            if(it==lis.end()){
                lis.push_back(x);
            }else{
                *it = x;
            }
        }
        return lis.size();
    }
public:
    int longestSubsequence(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<32;i++){
            vector<int> temp;
            for(int x:nums){
                if(x&(1<<i)){
                    temp.push_back(x);
                }
            }
            if(!temp.empty()){
                result = max(result,lis(temp));
            }
        }
        return result;
    }
};
