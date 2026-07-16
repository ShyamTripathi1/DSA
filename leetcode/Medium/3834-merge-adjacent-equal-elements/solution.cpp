class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;
        for(int ele:nums){
            long long x = ele;
        
        while(!st.empty() && st.top() == x){
            x += st.top();
            st.pop();
        }
        st.push(x);
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
