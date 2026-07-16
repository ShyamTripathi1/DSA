class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<vector<int>> adj_list(1e6+1);
        for(int i=0; i<routes.size(); i++){
            for(int j=0; j<routes[i].size(); j++){
                adj_list[routes[i][j]].push_back(i);
            }
        }
        int ans=0;
        queue<int> q;
        q.push(source);
        vector<int> visStop(1e6+1,0);
        vector<int> dis(1e6+1,0);
        visStop[source]=1;
        dis[source]=0;
        vector<bool> visBus(routes.size(),0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto bus:adj_list[node]){
                if(visBus[bus]==1) continue;
                visBus[bus]=1;
                for(auto stop:routes[bus]){
                    if(visStop[stop]==0){
                        visStop[stop]=1;
                        dis[stop]=dis[node]+1;
                        q.push(stop);
                    }
                }
            }
        }
        if(visStop[target]==0){
            return -1;
        }
        return dis[target];
    }
};
