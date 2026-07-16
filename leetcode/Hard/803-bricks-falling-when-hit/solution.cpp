class DSU { //tells whether u and v belong to same component in constant time O(1)--//
  public:
   vector<int> rank,parent,Size;
    DSU(int n) {
       rank.resize(n+1,0);
       parent.resize(n+1);
       Size.resize(n+1,1);

       for(int i=0;i<=n;i++) parent[i]=i;
    
    }

    int findUlp(int node) {
        if(node==parent[node]) return node;

        return parent[node]=findUlp(parent[node]);
    }

    void findUnionByRank(int u, int v) {
         int ulp = findUlp(u);
         int vlp = findUlp(v);
         if(ulp == vlp) return;
         //greater rank becomes parent
         if(rank[ulp] < rank[vlp])  swap(ulp, vlp);
         if(rank[ulp] == rank[vlp]) rank[ulp]++;
         parent[vlp] = ulp;
    }
    
     void Union(int u,int v) {  //it stores the Size as rank gets distorted while path compression
         int ulp=findUlp(u);
         int vlp=findUlp(v);

         if(ulp==vlp) return;
         if(Size[ulp] < Size[vlp]) swap(ulp, vlp);
         
         parent[vlp] = ulp;
         Size[ulp] += Size[vlp];
    } 
 };
  


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size(), m = grid[0].size(); 
        vector<vector<int>> bp(n, vector<int>(m,0));
        for(int idx=0; idx<hits.size(); idx++) {
           int i = hits[idx][0], j = hits[idx][1];
           if(grid[i][j]) {
              bp[i][j] = 1;
              grid[i][j] = 0;
           }
           hits[idx].push_back(idx);
        }

        DSU con(3e5), disCon(3e5);
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        unordered_map<int,int> mp;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        map<int,int> connected;
        
        for(int j=0; j<m; j++) {
            if(grid[0][j]) {
                q.push({0,j});
                vis[0][j] = 1;
            }
        } 

        while(q.size()) {
            auto [i,j] = q.front();
            q.pop();
            // cout<<i<<" "<<j<<endl;
            int ulp = con.findUlp(i*1000+j);
            connected[ulp] = max(connected[ulp], con.Size[ulp]);

            for(int k=0; k<4; k++) {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if(i1>=0 and i1<n and j1>=0 and j1<m and !vis[i1][j1] and grid[i1][j1]) {
                    vis[i1][j1] = 1;
                    q.push({i1, j1});
                    if(con.findUlp(i*1000+j) != con.findUlp(i1*1000+j1)) {
                        con.Union(i*1000+j, i1*1000+j1);
                    }
                }
            }
        }


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==0 or vis[i][j]) continue;
                 queue<pair<int,int>> q;
                 q.push({i,j});
                 vis[i][j] = 1;

                 while(q.size()) {
                    auto [i,j] = q.front();
                    q.pop();  

                    for(int k=0; k<4; k++) {
                        int i1 = i + dx[k];
                        int j1 = j + dy[k];
                        if(i1>=0 and i1<n and j1>=0 and j1<m and !vis[i1][j1] and grid[i1][j1]) {
                            vis[i1][j1] = 1;
                            q.push({i1, j1});
                            if(con.findUlp(i*1000+j) != con.findUlp(i1*1000+j1)) {
                                con.Union(i*1000+j, i1*1000+j1);
                            }
                        }
                    }
                }
            }
        }
 
        

        vector<int> ans(hits.size());
        reverse(hits.begin(), hits.end());

        for(auto it: hits) {
            int i = it[0], j = it[1], idx = it[2]; 
            // cout<<i<<" "<<j<<endl;
            int bricks = 0;
            if(!bp[i][j]) {
                ans[idx] = 0;
                continue;
            }
            grid[i][j] = 1;
            unordered_map<int,int> visPar;
            bool flag = false;
            for(int k=0; k<4; k++) {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if(i1>=0 and i1<n and j1>=0 and j1<m and grid[i1][j1]) {  
                    int ulp = con.findUlp(i1*1000+j1);
                    //take the bricks from unstable components
                    if(connected[ulp]==0 and !visPar[ulp]) { 
                        bricks += con.Size[ulp];
                        visPar[ulp] = 1;
                    }
                    if(con.findUlp(i*1000+j) != con.findUlp(i1*1000+j1)) {
                        con.Union(i1*1000+j1, i*1000+j);
                    } 
                    if(connected[ulp]) {
                        flag = true;
                    }
                }
            }

            if(flag or i==0) { 
                ans[idx] = bricks;
                connected[con.findUlp(i*1000+j)] = 1;
            }
        }
        return ans;
    }
};
