class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int s = grid.size();
        if(!s) return 0;
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qt;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == '1'){
                    count++;
                     //queue<pair<int,int>>qt;
                     qt.push({i,j});
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!qt.empty()){
        auto[x,y] = qt.front();
        qt.pop();
        for(auto[dx,dy]:dir){
            int p = x+dx;
            int q = y+dy;
            if(p>=0 && p<m && q>= 0 && q<n && grid[p][q] == '1'){
                grid[p][q] = 0;
                qt.push({p,q});
            }
        }
        }
            }
        }
        }
        return count;
    }
};
