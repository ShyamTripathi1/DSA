class Solution {
public:
    int maxProduct(int n) {
        vector<int> d;
        int p = 1;
        int cnt = 0;
     while(n> 0){
        d.push_back(n%10);
        n /= 10;
     }
     sort(d.begin(),d.end(), greater<int>());
     for(int ele:d){
       p *= ele;
       cnt++;
       if(cnt == 2) return p; 
     } 
      
     return -1;
    }
};
