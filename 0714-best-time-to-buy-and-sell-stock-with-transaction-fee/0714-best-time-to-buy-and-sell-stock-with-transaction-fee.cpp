class Solution {
private:
    int solve(int n,int fee,vector<int>& prices){
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][buy]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        return solve(n,fee,prices);
    }
};