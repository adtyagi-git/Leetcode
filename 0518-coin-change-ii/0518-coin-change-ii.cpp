class Solution {
private:
    int solve(int i,int amount,vector<vector<int>>& dp,vector<int>& coins){
        if(i==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int include=0;
        if(coins[i]<=amount){
            include=solve(i,amount-coins[i],dp,coins);
        }
        int exclude=solve(i-1,amount,dp,coins);
        return dp[i][amount]=include+exclude;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,dp,coins);
    }
};