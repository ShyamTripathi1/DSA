class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int c= 0.05*n;
        double sum = 0;
        sort(arr.begin(),arr.end());
        if(n<=5) return 0;
        for(int i = c;i<n-c;i++){
             sum += arr[i];
        }
        double sum1 =  sum/(n-2*c);
        return sum1;
    }
};
