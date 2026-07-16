class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        queue<pair<int,int>>qt;
        qt.push({start,0});
        int n = nums.size();
        vector<bool> ans(n,false);
        while(!qt.empty()){
            auto [i,d] = qt.front();
            qt.pop();
            if(nums[i] == target){
                return d;
            }
            for(auto k : {i-1,i+1}){
                if( k>=0 &&k<n && !ans[k]){
                    ans[k]= true;
                    qt.push({k,d+1});
                }
            }
        }
        return -1;
    }
};
