class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int p = edges[0][0];
        int q = edges[0][1];
        int m = edges[1][0];
        int n = edges[1][1];
        if(p == m|| p== n) {
           return p;
        } 
         return q;
    }
};
