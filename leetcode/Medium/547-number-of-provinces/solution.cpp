class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       vector<bool>ans(n,false);
       int p =0;
       for(int i =0;i<n;i++){
        if(!ans[i]){
            queue<int>q;
            q.push(i);
            ans[i] = true;
            while(q.size()){
                int node = q.front();
                q.pop();
         for(int j =0;j<n;j++){
            if(isConnected[node][j] == 1 && !ans[j]){
                q.push(j);
                ans[j] = true;

            }
        }
       }
       p=p+1;
        }
       }
       return p;
    }
};
