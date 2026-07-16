class Solution {
public:
    int differenceOfSums(int n, int m) {
        int count =0;
        int cnt =0;
        for(int i=1;i<=n;i++){
            if(i%m != 0 ){
                cnt += i;
            }
        }
            for(int j =1;j<=n;j++){
                if(j%m == 0){
                    count += j;
                }
            }
        return cnt - count;
    }
};
