class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string>st;
        int codes = 1<<k;
        for(int i = k;i<=n ; i++){
            string sub = s.substr(i-k,k);
        if(!st.count(sub)){
            st.insert(sub);
            codes--;
        }
        if(codes == 0){
            return true;
        }
        }
        return false;

    }
};
