class Solution {
private:
int solve(vector<int>&nums,vector<vector<int>>&dp,int l,int r){
    if(l==r) return nums[l];
    if(dp[l][r]==-1) return dp[l][r];
    int pickleft=nums[l]-solve(nums,dp,l+1,r);
    int pickright=nums[r]-solve(nums,dp,l,r-1);
    return dp[l][r]=max(pickleft,pickright);
}
    
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return solve(nums,dp,0,n-1)>=0;
    }
};