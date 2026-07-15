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
    int solve2(int i,int amount,vector<int>& coins){
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int i=0;i<amount+1;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
        }
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<amount+1;j++){
                int include=1e9;
                if(coins[i]<=j) include=1+dp[i][j-coins[i]];
                int exclude=dp[i-1][j];
                dp[i][j]=min(include,exclude);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int ans=solve(n-1,amount,dp,coins);
        // return (ans>=1e9)?-1:ans;
        return solve2(n-1,amount,coins);
    }
};