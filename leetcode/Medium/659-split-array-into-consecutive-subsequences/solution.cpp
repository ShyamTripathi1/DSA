class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, used;
        for (const int& num : nums)
            freq[num]++;
        for (const int& num : nums) {
            if (freq[num] == 0)
                continue;
            freq[num]--;
            if (used[num - 1] > 0) {
                used[num - 1]--;
                used[num]++;
            }
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num + 1]--;
                freq[num + 2]--;
                used[num + 2]++;
            }
            else
                return false;
        }
        return true;
    }
};
