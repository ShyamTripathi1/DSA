class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n = rooms.size();
       vector<bool>ans(n,false);
       stack<int>qt;
       qt.push(0);
       ans[0]= true;
       int cnt = 1;
       while(!qt.empty()){
        int x = qt.top();
        qt.pop();
        for(auto k:rooms[x] ){
            if(!ans[k]){
                ans[k] = true;
                cnt++;
                qt.push(k);
            }
        }
       }
       return cnt==n;

    }
};
