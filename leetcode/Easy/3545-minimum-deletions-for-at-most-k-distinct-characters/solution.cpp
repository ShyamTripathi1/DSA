class Solution {
public:
    int minDeletion(string s, int k) {
        int len = s.size();
        unordered_map<char,int> mp;
        for(char ele : s){
            mp[ele]++;
        }
       vector<int> ans;
       int ip =0;
       for(const auto& pair : mp){
        ans.push_back(pair.second);
        ip++;
       }
       if(ip <= k) return 0;
       sort(ans.begin(),ans.end());
       int sum = 0;
       int j =0;
       for(int i = 0 ; i<ans.size();i++){
            sum += ans[i];
            j++;
            if(j== (ip-k)) break;
       }
       return sum;

    }
};
