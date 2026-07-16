#include <stack>
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += 2 * k) {
            stack<char> st;

            int end = min(i + k, n);

            // Push characters into stack
            for (int j = i; j < end; j++) {
                st.push(s[j]);
            }

            // Pop and overwrite in reverse
            for (int j = i; j < end; j++) {
                s[j] = st.top();
                st.pop();
            }
        }

        return s;
    }
};

