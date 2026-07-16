class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string s1;
        long long sum = 0;
        for(int i =0;i<s.size();i++){
            if(s[i] != '0'){
                s1 += s[i];
            }
        }
        if(s1.empty())
            return 0;
            long long sum2 = stoll(s1);
            for(int i = 0;i<s1.size();i++){
                 sum += s1[i]-'0';
            }
        
        return sum2 * sum;
    }
};
