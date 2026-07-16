class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(!n) return 0;
        queue<pair<int,int>>qt;
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                   // queue<pair<int,int>>qt;
                    qt.push({i,j});
                    bool isclosed = true;

              
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!qt.empty()){
        auto[x,y] = qt.front();
        qt.pop();
        if( x== 0 || y== 0 || x== n-1 || y== m-1){
            isclosed = false;
        }
        for(auto[dx,dy] :dir){
            int p = x+dx;
            int q = y+dy;
            if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == 0){
                grid[p][q] = 1;
                qt.push({p,q});
                //count++;
            }
        }
        }
        if(isclosed) count++;
          }
            }
        }
       
        return count;
    }
};
