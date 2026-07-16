class Solution {
public:
vector<vector<string>> ans;
bool isPalindrome(string &str){
    int st =0,end = str.size()-1;
    while(st<end){
        if(str[st] != str[end]) return false;
        st++;
        end--;
    }
    return true;
}
    void helper(string &s,vector<string> &temp,int index){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        string pal_string;
        for(int i=index;i<s.size();i++){
            pal_string += s[i];
            if(isPalindrome(pal_string)){
                temp.push_back(pal_string);
                helper(s,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<string>temp;
         helper(s,temp,0);
         return ans;
    }
};
