class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        int left = 0, right = 0;
        set<int>st;
        while(right<n){
            if(st.size()>indexDiff){
                st.erase(st.find(nums[left]));
                left++;
            }
            auto it = st.lower_bound(nums[right]-valueDiff);
            if(it!=st.end() && *it<=nums[right]+valueDiff) return true;
            
            st.insert(nums[right]);
            right++;
        }
        return false;
        
    }
};
