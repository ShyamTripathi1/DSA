class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0;
        int b_count =0;
        for(const char& c:s){
                if(c == 'b'){
                    b_count++;
                }
                else{
                    if(b_count>0){
                        b_count--;
                        cnt++;
                    }
                }
        }
        return cnt;
    }
};
