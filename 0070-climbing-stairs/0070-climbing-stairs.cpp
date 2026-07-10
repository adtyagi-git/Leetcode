class Solution {
private:
    int solve(int n,int ind,vector<int>&dp){
        if(n==ind) return 1;
        if(ind>n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=(solve(n,ind+1,dp)+solve(n,ind+2,dp));
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,0,dp);
    }
};