class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Custom sort: sort by string concatenation comparison
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        vector<int> reversed;
        for (int i = 0; i < nums.size(); i++) {
            reversed.push_back(nums[i]);  // store sorted result (already descending)
        }

        string result = "";
        for (int num : reversed) {
            result += to_string(num);     // concatenate to string
        }

        // If result starts with '0', it means all are zeros
        if (result[0] == '0') return "0";

        return result;
    }
};

