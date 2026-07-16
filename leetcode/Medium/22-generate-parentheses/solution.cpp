class Solution {
public:
    vector<string>ans;
    void fnc(int open , int close , string path, int n){
       if(path.size()== 2*n){
        ans.push_back(path);
        return;
       }
       if(open<n){
        fnc(open+1,close,path+"(",n);
       }
       if(close<open){
        fnc(open,close+1,path+")",n);
       }
    }
    vector<string> generateParenthesis(int n) {
       // vector<string>ans;
         fnc(0,0,"",n);
        return ans;
        
    }
};
