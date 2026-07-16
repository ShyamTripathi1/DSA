class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
     //sort(happiness.begin(),happiness.end(),greater<int>());
     long long result =0;
     int cnt =0;
     priority_queue<int> pq;
     for(int &hap:happiness){
        pq.push(hap);
     }
     for(int i=0;i<k;i++){
        int hap = pq.top();
        pq.pop();
        result += max(hap-cnt,0);
        cnt++;
     }
     return result;
    }
};
