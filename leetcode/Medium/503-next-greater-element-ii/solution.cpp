class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int>ans(n,-1);

        stack<int>st;
        for(int i = 2*n - 1; i >= 0; i--)
        {
            while(!st.empty() && (a[i%n] >= st.top()))
            {
                st.pop();
            }
            if(!st.empty() && (i < n))
            {
                ans[i] = st.top();
            }
            st.push(a[i%n]);
        }
        return ans;
    }
};


