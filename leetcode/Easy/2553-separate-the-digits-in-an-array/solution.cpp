class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
       vector<int> res;
       for(int num:nums) {
        vector<int> digits;
        while(num){
            int rem = num%10;
            digits.push_back(rem);
            num /= 10;
        }
       res.insert(res.end(),digits.rbegin(),digits.rend());
       }
       return res;
    }
};
