class Solution {
private:
    string ans(string str1,string str2,int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string ans;
        int i=m,j=n;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        while(i){
            ans+=str1[i-1];i--;
        }
        while(j){
            ans+=str2[j-1];j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        return ans(str1,str2,m,n);
    }
};