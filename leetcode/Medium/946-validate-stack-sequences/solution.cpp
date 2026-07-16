class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        int i =0;
        int j =0;
        for (int x : pushed ){
         pushed[i]=x;
            i=i+1;
        
        
        while(i>0 && pushed[i-1]== popped[j]){
        i=i-1;
        j=j+1;
        }
        
       
        
        }
        return i==0;



        
    }
};
