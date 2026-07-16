class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        set<int> result;

        // Check for nums1 and nums2
        for (int x : s1) {
            if (s2.count(x)) {
                result.insert(x);
            }
        }
        // Check for nums1 and nums3
        for (int x : s1) {
            if (s3.count(x)) {
                result.insert(x);
            }
        }
        // Check for nums2 and nums3
        for (int x : s2) {
            if (s3.count(x)) {
                result.insert(x);
            }
        }

        // Convert set to vector
        return vector<int>(result.begin(), result.end());
    }
};

