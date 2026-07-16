class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
            while(ans.size()>1){
            int a = ans.back();
            int b = ans[ans.size()-2];
            int g = gcd(a,b);
            if(g>1){
                ans.pop_back();
                ans.pop_back();
                long long lcm = (1LL*a*b)/g;
                ans.push_back((int)lcm);
            }
            else{
                break;
            }
            }

        }
        return ans;
    }
};
