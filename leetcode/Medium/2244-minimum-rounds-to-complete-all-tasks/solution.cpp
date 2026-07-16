class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        int cnt =0;
       // sort(tasks.begin(),tasks.end());
        unordered_map<int,int>mp;
        for(int ele:tasks){
            mp[ele]++;
        }
        for(const auto& pair:mp){
            if(pair.second == 1) return -1;
             if(pair.second % 3 == 0) cnt += pair.second/3;
             else{
                cnt += pair.second/3 +1;
             }
        }
        return cnt;
    }
};
