class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long, int>> dq;  // store segments: (segment_sum, start_index)
        long long sum = 0;               // total sum of all segments in deque
        int ans = INT_MAX;               // minimum length of valid subarray

        for (int i = 0; i < nums.size(); i++) {
            long long cnt = nums[i];     // current element value (may start a new segment)
            int l = i;                   // start index of this segment

            // --- Step 1: Merge with previous segments if current value is negative ---
            // Negative values can "cancel out" positive segments at the end of the deque.
            while (cnt < 0 && dq.size()) {
                cnt += dq.back().first;   // merge last segment’s sum into current
                sum -= dq.back().first;   // remove that segment from total sum
                l = dq.back().second;     // extend segment start index backward
                dq.pop_back();            // remove merged segment
            }

            // --- Step 2: Push positive (or non-negative) segment ---
            if (cnt >= 0) {               // only keep non-negative merged segments
                dq.push_back({cnt, l});   // append as new segment
                sum += cnt;               // update total sum of current window
            }

            // --- Step 3: Try to shrink from the left if possible ---
            // While removing the front still keeps sum >= k, pop it to shorten window.
            while (dq.size() && sum - dq.front().first >= k) {
                sum -= dq.front().first;
                dq.pop_front();
            }

            // --- Step 4: Check current total sum ---
            // If current total sum >= k, we found a valid window.
            if (sum >= k)
                ans = min(ans, i - dq.front().second + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
