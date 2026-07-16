class Solution {
public:
    using ll = long long;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> rowsum(m, 0);
        vector<ll> colsum(n, 0);

        ll total = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rowsum[i] += grid[i][j];
                colsum[j] += grid[i][j];
                total += grid[i][j];   // ✅ FIX
            }
        }

        if(total % 2 != 0) return false;

        ll upper = 0;
        for(int i = 0; i < m - 1; i++){
            upper += rowsum[i];
            if(upper == total - upper) return true;
        }

        ll left = 0;
        for(int j = 0; j < n - 1; j++){
            left += colsum[j];
            if(left == total - left) return true;  // ✅ FIX
        }

        return false;
    }
};
