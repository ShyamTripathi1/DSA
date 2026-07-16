class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i==j) continue;
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                int dist1 = a*a + b*b;
                for(int k=0;k<n;k++){
                    if(i==k || j== k) continue;
                    int c = points[i][0]-points[k][0];
                    int d = points[i][1]-points[k][1];
                    int dist2 = c*c + d*d;
                    if(dist1 == dist2) cnt++;
                }

            }
        }
        return cnt;
    }
};
