class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int count =0;
        for(int i =0;i<n;i++){
            if((num[i]-'0')%2!=0){
                count=i+1;
                 //count = max(count,num[i]);
            }
        }
        return num.substr(0, count);  
    }
};
