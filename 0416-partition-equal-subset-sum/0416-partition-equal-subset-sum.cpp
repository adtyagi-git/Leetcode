class Solution {
private:
    bool solve(int i,int k,vector<int>& nums,vector<vector<int>>& dp){
        if(k==0) return true;
        if(i==0) return k==nums[0];
        if(dp[i][k]!=-1) return dp[i][k];
        bool include=false;
        if(nums[i]<=k){
            include=solve(i-1,k-nums[i],nums,dp);
        }
        bool exclude=solve(i-1,k,nums,dp);
        return dp[i][k]=include||exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum&1) return false;
        else{
            int k=sum/2;
            vector<vector<int>>dp(n,vector<int>(k+1,-1));
            return solve(n-1,k,nums,dp);
        }
    }
};