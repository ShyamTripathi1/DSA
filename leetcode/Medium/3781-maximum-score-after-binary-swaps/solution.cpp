class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        vector<int> b = nums;
        long long res = 0;
        priority_queue<int> pq;
        int n = b.size();
        for(int i =0;i<n;++i){
            pq.push(b[i]);
            if(s[i] == '1'){
                res += pq.top();
                pq.pop();
            }
        }
        return res;
    }
};
