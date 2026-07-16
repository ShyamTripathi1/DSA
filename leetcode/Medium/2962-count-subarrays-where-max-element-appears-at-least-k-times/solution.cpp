class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int MaxEle =0, n = nums.size();
        for(int i=0;i<n;i++)
        MaxEle = max(MaxEle,nums[i]);
        long long total =0;
        int count =0, start=0,end =0;
        while(end<n){
            if(nums[end] == MaxEle)
            count++;
            while(count == k){
                total += n-end;
                if(nums[start] == MaxEle)
                count--;
                start++;
            }
            end++;
        }
        return total;
    }
};
