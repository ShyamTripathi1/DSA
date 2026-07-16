class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        queue<array<int,3>>qt;
        qt.push({0,0,1});
        grid[0][0] = 1;
        while(!qt.empty()){
            auto[x,y,d] = qt.front();
            qt.pop();
            if(x == n-1 && y == n-1) return d;
            for(auto[dx,dy] : dir){
                int p=x+dx, q = y+dy;
                if (p >= 0 && p < n && q >= 0 && q < n && grid[p][q] == 0) {
                    qt.push({p,q,d+1});
                    grid[p][q] = 1;
                }
            }
        }
        return -1;
    }
};
