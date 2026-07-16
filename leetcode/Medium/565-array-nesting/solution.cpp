int rec(vector<int>& nums,int i,vector<bool>& vis){
    if(vis[i]){
        return 0;
    }

    vis[i]=true;

    

    return 1+rec(nums,nums[i],vis);
    

    
}

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        vector<bool> vis(nums.size(),false);
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(!vis[i]){

            ans=max(ans,rec(nums,i,vis));
            }
        }

        return ans;
        
    }
};
