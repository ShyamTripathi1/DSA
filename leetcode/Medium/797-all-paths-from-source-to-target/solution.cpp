class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        queue<pair<int, vector<int>>> qt;
        qt.push({0, {0}});
        vector<vector<int>> ans;
        while(!qt.empty()){
            auto [node,path] = qt.front();
            qt.pop();
            if(node == target){
                ans.push_back(path);
            }
           for(int k : graph[node]){
           vector<int> temp = path;
           temp.push_back(k);
           qt.push({k, temp});

            }
        }
        return ans;
    }
};
