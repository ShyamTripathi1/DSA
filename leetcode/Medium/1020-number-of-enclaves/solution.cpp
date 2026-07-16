class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Step 1: Remove boundary land
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][n-1] == 1) dfs(grid, i, n-1);
        }

        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1) dfs(grid, 0, j);
            if(grid[m-1][j] == 1) dfs(grid, m-1, j);
        }

        // Step 2: Count remaining land
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};
