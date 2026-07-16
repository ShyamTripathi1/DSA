class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
       int m = isWater.size();
       int n=isWater[0].size();
       queue<pair<int,int>>qt;
       for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(isWater[i][j] == 1){
                isWater[i][j] = 0;
                qt.push({i,j});
            }
            else{
                isWater[i][j] = -1;
            }
        }
       }
       vector<pair<int,int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
       while(!qt.empty()){
        auto[x,y] = qt.front();
        qt.pop();
        for(auto[dx,dy]:dir){
        int p = x+dx;
        int q = y+dy;
        if((p>=0 && p<m)&&(q>=0 && q<n) &&(isWater[p][q] == -1)){
            isWater[p][q] = isWater[x][y]+1;
            qt.push({p,q});
        }
        
       }
       }
return isWater;
    }
};
