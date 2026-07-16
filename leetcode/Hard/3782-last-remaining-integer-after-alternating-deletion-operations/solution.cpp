class Solution {
public:
    long long lastInteger(long long n) {
      long long t = n;
        
        long long cnt = t, start = 1, gap =1 ;
        bool left = true;
        while(cnt>1){
            if(!left && (cnt%2 ==0)){
                start += gap;
            }
            gap<<=1;
            cnt = (cnt+1)>>1;
            left =! left;
        }
        return start;
    }
};
