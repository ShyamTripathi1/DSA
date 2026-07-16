class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int maxi = max_element(nums.begin(),nums.end())-nums.begin();
        int mini = min_element(nums.begin(),nums.end())-nums.begin();
        if(mini>maxi){
            swap(mini,maxi);
        }
        int left = maxi+1;
        int right = n-mini;
        int both = (mini+1)+(n-maxi);
        return min({left,right,both});

    }
};
