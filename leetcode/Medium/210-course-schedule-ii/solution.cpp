class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> indeg(numCourses,0);
      vector<vector<int>> graph(numCourses);
      int n = prerequisites.size();
      for(int i =0;i<n;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
                graph[b].push_back(a);
                indeg[a] = indeg[a]+1;
        }
        queue<int> qt;
        int m = numCourses;
        for(int i =0;i<m;i++){
            if (indeg[i] == 0){
                qt.push(i);
            }
        }
        vector<int> order;
        while(!qt.empty()){
            int x = qt.front();
            qt.pop();
            order.push_back(x);
            for(int k:graph[x]){
                indeg[k] = indeg[k]-1;
                if(indeg[k] == 0){
                    qt.push(k);
                }
            }
        }
      if (order.size() == numCourses) return order;
      return {}; 


    }
};
