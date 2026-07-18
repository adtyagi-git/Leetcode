class Solution {
private:
    const int mod=1e9+7;
    long long lis(string &s,string &t,int m,int n){
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for (int i=0;i<=m;i++)
            dp[i][0] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    unsigned long long take=dp[i-1][j-1];
                    unsigned long long nottake=dp[i-1][j];
                    dp[i][j]=take+nottake;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
public:
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        return lis(s,t,m,n);
    }
};