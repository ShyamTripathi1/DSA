class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> maxi;
        for(int i =0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                double ans = (double)arr[i]/arr[j];
                maxi.push({ans,{arr[i],arr[j]}});
        if(maxi.size()>k){
            maxi.pop();
        }
            }
        }
        return {maxi.top().second.first,maxi.top().second.second};
    }
};
