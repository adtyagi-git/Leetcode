class Solution {
private:
    int solve(int n,int count,vector<int>& prices){
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(count+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=1;buy>=0;buy--){
            for(int cap=count; cap>0; cap--){
                if(buy==1){
                dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                }
                else{
                    dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                }
            }
            
        }
    }
    return dp[0][1][count];
}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),count=2;
        return solve(n,count,prices);
    }
};