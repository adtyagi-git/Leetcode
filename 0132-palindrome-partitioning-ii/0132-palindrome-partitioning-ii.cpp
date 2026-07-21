class Solution {
private:
    bool ispalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }    
    int solve(int i,string &s,int n,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        string a;
        int mini=INT_MAX;
        int cost=0;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                cost=1+solve(j+1,s,n,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,n,dp)-1;
    }
};