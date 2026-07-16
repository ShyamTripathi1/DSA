class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans(n2);
        vector<int> res(n1);
        stack<int> st;

        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] > st.top())
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    res[i] = ans[j];
                    break;
                }
            }
        }
        return res;
    }
};
