class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> maxi;
        int n = score.size();
        vector<string>ans(n);
        for(int i =0;i<n;i++){
            maxi.push({score[i],i});
        }
        int rank = 1;
        while(!maxi.empty()){
            int idx = maxi.top().second;
            maxi.pop();
            if(rank == 1) ans[idx] = "Gold Medal";
            else if(rank == 2) ans[idx] = "Silver Medal";
            else if(rank == 3) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(rank);
            rank++;
        }
        return ans;
    }
};
