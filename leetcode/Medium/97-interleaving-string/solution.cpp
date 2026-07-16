class Solution {
public:
    bool find(string &s1,string &s2,string &s3,vector<vector<vector<int>>> &dp,int i,int j,int k)
    {
        if(k == s3.size() && i == s1.size() && j == s2.size())
        {
            return true;
        }
        if(k == s3.size())
        {
            return false;
        }
        if(i>=s1.size() && j>=s2.size())
        {
            return false;
        }
        if(dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        bool res=false;
        if(i<s1.size() && s1[i] == s3[k])
        {
            res=res || find(s1,s2,s3,dp,i+1,j,k+1);
        }
        if(j < s2.size() && s2[j] == s3[k])
        {
            res=res || find(s1,s2,s3,dp,i,j+1,k+1);
        }
        dp[i][j][k]=res;
        return res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size(),-1)));
        return find(s1,s2,s3,dp,0,0,0);
    }
};
