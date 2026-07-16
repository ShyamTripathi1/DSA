class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int k = image[sr][sc];
       if(k== color){
        return image;
       }
       int m = image.size();
       int n = image[0].size();
       queue<pair<int,int>>qt;
       qt.push({sr,sc});
        vector<pair<int,int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
       while(!qt.empty()){
        auto [x,y] = qt.front();
        qt.pop();
         image[x][y] = color;
       for(auto [dx,dy] : dir){
        int p = x+dx;
        int q = y+dy;
        if(p>=0 && p<m && q>=0 && q<n && image[p][q] ==k){
            qt.push({p,q});
        }
       }
       }
       return image;
    }
};
