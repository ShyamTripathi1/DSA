class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int start =0,end=0 ;
        int n=nums.size();
        long long product =0,count=0;
        while(end<n){
            product += nums[end];
            while(product >= (k*1.0)/(end-start+1)){
                product -= nums[start];
                start++;

            
            }
            count += (end-start+1);
            end++;
        }
        return count;
    }
};
