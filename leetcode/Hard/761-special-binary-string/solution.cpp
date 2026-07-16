class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> ans;
        int start = 0;
        int sum = 0;
        for(int i =0;i<s.size();i++){
            sum += s[i] == '1'?1:-1;
            if(sum == 0){
                string inner = s.substr(start+1,i-start-1);
                ans.push_back("1" + makeLargestSpecial(inner) +'0' );
                start = i+1;
            }
        }
        sort(ans.begin(),ans.end(),greater<string>());
        string result;
        for(string &str : ans){
            result += str;
        }
        return result;
    }
};
