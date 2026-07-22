class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      
       int n = arr.size();
       int cnt = 0;
       int sum = 0;
       int i = 0;
       while(i<k){
        sum += arr[i];
        i++;
       }
        if(sum / k >= threshold){
            cnt++;

        }
        for(int j =k;j<n;j++){
         sum += arr[j];
         sum -= arr[j-k];
         if(sum / k >= threshold){
            cnt++;
         }
        }
       return cnt;
    }
};
