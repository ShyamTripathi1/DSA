class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        sort(nums.begin(),nums.end());
        int left =0;
        int right = n/2;
        while(left<n/2 && right <n){
            if( 2 * nums[left] <= nums[right]){
                count+=2;
                left++;
                right++;

        }
        else{
            right++;  
        }
        }
        return count;
    }
};
