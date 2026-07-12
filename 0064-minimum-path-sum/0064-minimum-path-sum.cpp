class Solution {
private:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> & grid){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return grid[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=INT_MAX,up=INT_MAX;
        if(i>0){
            up=grid[i][j]+solve(i-1,j,dp,grid);
        }
        if(j>0){
            left=grid[i][j]+solve(i,j-1,dp,grid);
        }
        return dp[i][j]=min(left,up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,grid);
    }
};