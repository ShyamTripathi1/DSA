class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> org = mat;
        k=k%n;
        for(int i =0;i<m;i++){
            if(i%2 == 0){
                rotate(rbegin(mat[i]),rbegin(mat[i])+k,rend(mat[i]));
            }
            else{
                rotate(begin(mat[i]),begin(mat[i])+k,end(mat[i]));
            }
        }
        return mat == org;
    }
};
