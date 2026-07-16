class Solution {
public:
    bool hasAlternatingBits(int n) {
        string res = "";
        while(n>0){
            int rem = n%2;
            res += (rem + '0');
            n /= 2;
        }
       // reverse(res.begin(),res.end());
        for(int i =0;i<res.size()-1;i++){
            if(res[i] == res[i+1] ) return false;
        }
        return true;
        
    }
};
