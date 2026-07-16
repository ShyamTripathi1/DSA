class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans;
        int m = ans.size();
        for(int i =0;i<n;i++){
            if(i<n-1 && num[i]==num[i+1] && num[i] == num[i+2]){
              if(m==3){
                ans= max(ans,num.substr(i,3));
              }
              else{
                ans = num.substr(i,3);
                m=3;
              }
            }
           
          
        }
        return ans;
        
       

        
    }
};
