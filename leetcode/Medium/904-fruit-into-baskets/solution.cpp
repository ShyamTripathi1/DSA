class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0,l=0,r=0;
        unordered_map<int,int>mp;
        for(int r=0;r<n;r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                  mp.erase(fruits[l]);
                }
                  l++;
            }
                maxlen = max(maxlen,r-l+1);
        }
       return maxlen;
    }
};
