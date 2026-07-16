class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int count =0;
        for(int i =0;i<nums.size();i++){
        int maximum = nums[i];
        int minimum = nums[i];
        int len =1;
        for(int j =i+1;j<(int)nums.size();j++){
     
         maximum = max(maximum,nums[j]);
         minimum = min(minimum,nums[j]);

         if(maximum - minimum ==1){
            len = j-i+1;
            count = max(count,len);
         }
         else if(maximum-minimum>1){
          break;

         }
        }
    }
          

        return count;
        
    }
};
