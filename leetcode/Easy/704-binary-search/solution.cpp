class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;

        while (left <= right) {
            if (nums[middle] == target)
                return middle;
            if (target > nums[middle])
                left = middle + 1;
            else if (target < nums[middle])
                right = middle - 1;
            
            middle = (left + right) / 2;
        }

        return -1;
    }
};
