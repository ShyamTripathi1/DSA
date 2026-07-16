class Solution {
public:
    string winningPlayer(int x, int y) {
        int win;
        if(y<4) return "Bob";
      while(x>0 && y>3){
        if(x>0 && y>3){
            x=x-1;
            y=y-4;
            win=0;
        }
        if(x>0 && y>3){
            x=x-1;
            y=y-4;
            win=1;
        }
      }
      if(win==1) return "Bob";
      return "Alice";
    }
};
