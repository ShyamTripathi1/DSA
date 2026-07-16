class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res = 0;
        priority_queue<int> pq;
        for(int i = 0, n = stations.size(); startFuel < target; ++res){
            while(i < n && stations[i][0] <= startFuel) pq.push(stations[i++][1]);
            if(pq.empty()) return -1;
            startFuel += pq.top(); pq.pop();
        }
        return res;
    }
};
