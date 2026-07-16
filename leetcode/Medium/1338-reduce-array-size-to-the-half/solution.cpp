class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int ele:arr){
            mp[ele]++;

        }
        priority_queue<int> maxi;
        for(auto x:mp){
            maxi.push(x.second);
        }
        int cnt =0;
        int removed = 0;
        while(removed<n/2){
            removed += maxi.top();
                maxi.pop();
                cnt++;
            }
        
        return cnt;
    }
};
