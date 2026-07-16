class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        vector<int>count(n+1);
        for(int i =0;i<m;i++){
            int a = trust[i][0];
            int b = trust[i][1];
            count[a]--;
            count[b]++;
        }
        for(int i =1;i<=n;i++){
            if(count[i] == n-1) return i;
        }
         return -1;
    }
};
