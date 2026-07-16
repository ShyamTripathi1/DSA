class Solution {
public:
    void wiggleSort(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      vector<int> ans(arr.size());
      int i = 1, j = arr.size()-1;
      while(i<arr.size()){
        ans[i]= arr[j];
        i = i+2;
        j--;
      }
       i=0;
       while(i<arr.size()){
        ans[i]= arr[j];
        i = i+2;
        j--;
       }
     for(int k =0;k<arr.size();k++){
        arr[k]= ans[k];
     }

    }
};
