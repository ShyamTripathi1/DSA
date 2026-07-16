class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size(); 
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            int count =0;
            for(int j =0;j<accounts[i].size();j++){
                count += accounts[i][j];
                maximum = max(maximum,count);

            }
        }
       return maximum;
        
        
    }
};
