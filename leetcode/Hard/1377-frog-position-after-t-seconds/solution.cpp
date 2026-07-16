class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
       vector<vector<int>>adj(n+1);
       for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
            queue<tuple<int,int,double,int>>qt;
            qt.push({1,-1,1.0,0});
            while(!qt.empty()){
               auto[node,parent,prob,time] = qt.front();
               qt.pop();
               if(time == t){
                if(node == target){
                    return prob;
                }
                    continue;
                }
               
               
                int child = adj[node].size();
                if(parent != -1){
                    child--;
                }
               
               if(child == 0){
                if(node == target){
                    return prob;
                }
               }
               else{
                for(auto k : adj[node]){
                    if(k != parent){
                        qt.push({k,node,prob/child, time+1});
                    }
                }
               }
    }
      return 0.0;

    }
};
