class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(!n) return 0;
        int count = 0;
        vector<int>row(n,0);
        vector<int>col(m,0);
        queue<pair<int,int>>qt;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                    qt.push({i,j});
                }
            }
        }
        while(!qt.empty()){
            auto[x,y] = qt.front();
            qt.pop();
           if(row [x]>1 || col[y] >1){
                count++;
            }
            }
        return count;
    }
};
