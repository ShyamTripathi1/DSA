class Solution {
public:
 vector<vector<int>> memo;
 int fnc(int i , int amount , vector<int>& coins){
    if(amount == 0){
        return 1;
    }
    if(i == coins.size()){
        return 0;
    }
    if(memo[i][amount] != -1){
        return memo[i][amount];
    }
    int res = 0;
   
        if(coins[i] <= amount){
            res = res + fnc(i, amount - coins[i],coins);
        }
    
    res = res + fnc(i+1,amount,coins);
    memo[i][amount] = res;
    return res;
}
    int change(int amount, vector<int>& coins) {
         memo.resize(coins.size(), vector<int>(amount + 1, -1));
       return fnc(0,amount,coins);
    }
};
