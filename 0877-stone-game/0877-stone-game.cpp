class Solution {
private:

public:
    bool stoneGame(vector<int>& piles) {
    //     int n=piles.size();
    //     int l=0,r=n-1;
    //     vector<vector<int>>dp(n,vector<int>(n,0));
    //     for(int i=0;i<n;i++){
    //         dp[i][i]=piles[i];
    //     }
    //     for(int l=n-1;l>=0;l--){
    //         for(int r=l+1;r<n;r++){
    //             int pickleft=piles[l]+dp[l+1][r];
    //             int pickright=piles[r]+dp[l][r-1];
    //             dp[l][r]=max(pickleft,pickright);
    //         }
    //     }
    //     return dp[0][n-1]>=0;
    return true;
    }
};