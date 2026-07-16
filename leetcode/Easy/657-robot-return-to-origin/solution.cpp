class Solution {
public:
    bool judgeCircle(string moves) {
        int a =0;
        int b =0;
        for(char x: moves){
            if(x == 'R') a--;
            if(x == 'L') a++;
            if(x == 'U') b++;
            if(x == 'D') b--;
        }
        if( a == 0 && b == 0 ) return true;
        return false;
        
    }
};
