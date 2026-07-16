class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> cumx(m, vector<int>(n,0));
      vector<vector<int>> cumy(m, vector<int>(n,0));
      int cnt = 0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cumx[i][j] = (grid[i][j] == 'X');
            cumy[i][j] = (grid[i][j] == 'Y');
            if(i-1>= 0){
                cumx[i][j] += cumx[i-1][j];
                cumy[i][j] += cumy[i-1][j];
            }
            if(j-1>= 0){
                cumx[i][j] += cumx[i][j-1];
                cumy[i][j] += cumy[i][j-1];
            }
            if(i-1 >= 0 && j-1 >= 0){
                cumx[i][j] -= cumx[i-1][j-1];
                cumy[i][j] -= cumy[i-1][j-1];
            }


            
        if(cumx[i][j] == cumy[i][j] && cumx[i][j] > 0){
            cnt++;
        }
       
      }
      }
       return cnt;
    }
};
