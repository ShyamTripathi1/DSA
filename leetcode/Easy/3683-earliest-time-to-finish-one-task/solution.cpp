class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int minimum = INT_MAX;
        for(int i =0;i<n;i++){
            int finish = tasks[i][0]+tasks[i][1];
                 minimum = min(minimum,finish);
        }
        return minimum;
    }
};
