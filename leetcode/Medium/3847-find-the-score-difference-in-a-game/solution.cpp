class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int fp = 0;
        int sp = 0;
        bool active = true;
        for(int i =0;i<n;i++){
            if(nums[i]%2 == 1){
                active = !active;
            }
            if(i%6 == 5){
               active = !active;
            }
            if(active){
                fp += nums[i];
            }
            else{
                sp += nums[i];
            }
        }
        return fp-sp; 
    }
};
