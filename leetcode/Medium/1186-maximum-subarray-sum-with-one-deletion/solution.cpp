class Solution {
public:
    int maximumSum(vector<int>& arr) {
       int nodelete = arr[0];
        int onedelete = INT_MIN;
        int res = arr[0];
        int n = arr.size();
     for(int i = 1;i<n;i++){
        int prevnodelete = nodelete;
        int prevonedelete = onedelete;
        nodelete = max(nodelete+arr[i],arr[i]);
        int v2;
        if(prevonedelete == INT_MIN){
            v2 = arr[i];
        }
        else{
            v2 = prevonedelete + arr[i];
        }
        onedelete = max(v2,prevnodelete);
        res = max(res,max(onedelete , nodelete));
     }   
     return res;
    }
};
