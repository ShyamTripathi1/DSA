class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, nums.size() - 1) >= 0;
    }
    int canWin(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int takeLeft  = nums[left]  - canWin(nums, left + 1, right);
        int takeRight = nums[right] - canWin(nums, left, right - 1);
        return max(takeLeft, takeRight);
    }
};

