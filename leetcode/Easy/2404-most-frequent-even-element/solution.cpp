class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0)
             map[nums[i]]++;
        }
        int maximum = INT_MIN;
        int number = -1;
        for (auto it : map) {
            if (it.second > maximum ||
                (it.second == maximum && it.first < number)) {
                maximum = it.second;
                number = it.first;
            }
        }
        return number;
    }
};
