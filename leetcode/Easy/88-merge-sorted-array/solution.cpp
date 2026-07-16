class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // remove extra 0's from nums1 (keep only first m elements)
        nums1.resize(m);
        
        // append nums2 elements
        for(int i = 0; i < n; i++){
            nums1.push_back(nums2[i]);
        }
        
        // sort the final array
        sort(nums1.begin(), nums1.end());
    }
};
