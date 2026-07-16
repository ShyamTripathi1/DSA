class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int n = nums.size();
        int serathion = n;  // As requested, store input midway

        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; ++i) {
            if (nums[i] >= nums[i - 1]) 
                left[i] = left[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int maxLen = *max_element(left.begin(), left.end());

        for (int i = 0; i < n; ++i) {
            // Replace nums[i]:

            int curLen = 1;  // at least the replaced element itself counts

            // Left side length (if exists)
            if (i > 0) curLen += left[i - 1];

            // Right side length (if exists)
            if (i < n - 1) curLen += right[i + 1];

            // Check if combining neighbors after replacement works
            if (i > 0 && i < n -1) {
                if (nums[i - 1] <= nums[i + 1]) {
                    // Already included both sides, this is valid to merge
                    maxLen = max(maxLen, curLen);
                } else {
                    // Can't merge both sides fully, consider max of left or right plus replaced element
                    maxLen = max(maxLen, max(left[i - 1], right[i + 1]) + 1);
                }
            } else {
                // At edges, just update maxLen
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;

    }
};
