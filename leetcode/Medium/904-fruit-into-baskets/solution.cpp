class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     int n = fruits.size();
     unordered_map<int,int> mp;
     int res = 0;
     int low = 0, high = 0;
     for(int high = 0;high<n;high++){
        mp[fruits[high]]++;
     
     while(mp.size() > 2 ){
        mp[fruits[low]]--;
        if(mp[fruits[low]] == 0){
            mp.erase(fruits[low]);
        }
        low++;
     }
   
        int len = high-low+1;
        res = max(len,res);
     }
     return res;
        
    }
};
