class Solution {
// private:
//     int solve(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
//         if(i==n-1) return triangle[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int down=triangle[i][j]+solve(i+1,j,n,triangle,dp);
//         int diagonal=triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
//         dp[i][j]=min(down,diagonal);
//         return dp[i][j];
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // // return solve(0,0,n,triangle,dp);
        // for(int j=0;j<n;j++){
        //     dp[n-1][j]=triangle[n-1][j];
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int down=triangle[i][j]+dp[i+1][j];
        //         int diagonal=triangle[i][j]+dp[i+1][j+1];
        //         dp[i][j]=min(down,diagonal);
        //     }
        // }
        // return dp[0][0];
        vector<int> prev(n,-1);
        vector<int>curr(n,-1);
        for(int j=0;j<n;j++){
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+prev[j];
                int diagonal=triangle[i][j]+prev[j+1];
                curr[j]=min(down,diagonal);
            }
            prev=curr;
        }
        return prev[0];
    }
};