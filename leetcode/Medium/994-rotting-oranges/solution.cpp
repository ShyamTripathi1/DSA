class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>qt;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 2){
                    qt.push({i,j});

                }
                if(grid [i][j] == 1){
                    fresh = fresh+1;
                }
            }
        }
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int time = 0;
        while(!qt.empty() && fresh){
            int s = qt.size();
            for(int k =0;k<s;k++){
                auto [x,y] = qt.front();
                qt.pop();
                for(auto[dx,dy]:dir){
                    int p = x+dx;
                    int q = y+dy;
                    if(p>=0 && p<m && q>=0 && q<n && grid[p][q] == 1){
                        grid[p][q] = 2;
                        fresh = fresh-1;
                        qt.push({p,q});
                    }
                }
            }
            time++;

        }
        if(fresh == 0)
        return time;
        else
        return -1;
        
    }
};
