class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int minIndex = -1;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    minIndex = j;
                }
            }
            int maxi = INT_MIN;
            for (int k = 0; k < n; k++) {
                maxi = max(maxi, matrix[k][minIndex]);
            }
            if (maxi == mini) {
                ans.push_back(mini);
            }
        }
        return ans;
    }
};

