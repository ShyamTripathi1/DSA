class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int cnt =1;
        int ans =-1;
        sort(arr.begin(),arr.end());
        for(int i=1;i<=n;i++){
            if(i<n && arr[i]==arr[i-1]){
                cnt++;
            }
            else{
                if(arr[i-1] == cnt) 
                ans = max(ans,arr[i-1]);
                cnt =1;
            }

        }
        return ans;
    }
};
