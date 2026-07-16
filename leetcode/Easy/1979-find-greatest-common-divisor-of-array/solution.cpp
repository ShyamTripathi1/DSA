class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maximum = *max_element(nums.begin(),nums.end());
        int minimum = *min_element(nums.begin(),nums.end());
        while(minimum !=0){
            int temp = minimum;
            minimum = maximum % minimum;
            maximum = temp;
        }
        return maximum;
    }
};
