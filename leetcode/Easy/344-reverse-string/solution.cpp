class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>St;
        for(int i=0;i<s.size();i++){
            St.push(s[i]);
        }
        int i=0;
        while(!St.empty()){
            s[i]=St.top();
            i++;
            St.pop();
        }

        
    }
};
