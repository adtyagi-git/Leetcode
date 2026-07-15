class Solution {
private:
    int solve(int i,int amount,vector<vector<int>>& dp,vector<int>& coins){
        if(i==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int include=1e9;
        if(coins[i]<=amount){
            include=1+solve(i,amount-coins[i],dp,coins);
        }
        int exclude=solve(i-1,amount,dp,coins);
        return dp[i][amount]=min(include,exclude);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,dp,coins);
        return (ans>=1e9)?-1:ans;
    }
};