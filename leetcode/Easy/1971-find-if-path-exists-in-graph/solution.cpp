class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        set<int>vt;
        vt.insert(source);
        stack<int>qt;
        qt.push(source);
        while(!qt.empty()){
            int node = qt.top();
            qt.pop();
           if(node == destination) return true;
           for (int adj : graph[node]) {
                if (vt.find(adj) == vt.end()) {
                    qt.push(adj);
                    vt.insert(adj);
                }
            }
        }
        return false;
        
    }
};
