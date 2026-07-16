class Solution {
public:
    vector<string> letterCasePermutation(string s) {
      queue<string>qt;
      qt.push("");
      for(char c:s) {
        int size = qt.size();
        for(int i =0;i<= size-1;i++){
            auto k = qt.front();
            qt.pop();
            if(isalpha(c))
            {
                qt.push(k+(char)tolower(c));
                qt.push(k+(char)toupper(c));

            }
            else{
                qt.push(k+c);
            }
        }
      }
      vector<string> ans;
        while (!qt.empty()) {
            ans.push_back(qt.front());
            qt.pop();
        }

        return ans;
    }
};
