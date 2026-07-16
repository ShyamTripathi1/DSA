class Solution {
public:
    int func(int i , vector<int>&dp){
        if(i <= 3)return i ; 
        if(dp[i] != -1)return dp[i] ; 
        int ans = 0 ; 
        for(int j = 1 ; j < i ; j ++){
            ans = max({ans , j * func(i - j , dp)}) ; 
        }
        return dp[i] = ans ; 
    }
    int integerBreak(int n) {
        if(n == 2)return 1 ; 
        if(n == 3)return 2 ; 
        if(n == 4)return 4 ; 
        vector<int>dp(n + 1 , -1) ; 
        return func(n , dp) ; 
    }
};


// 
