class Solution {
public:
    int expandaroundcenter(string s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;right++;
        }
        return right-left-1;
    }
    bool ispalindrome(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return dp[i][j]=false;
        else return dp[i][j]=ispalindrome(i+1,j-1,s,dp);
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n=s.size();
        // int start=0,end=0;
        // for(int i=0;i<n;i++){
        //     int odd=expandaroundcenter(s,i,i);
        //     int even=expandaroundcenter(s,i,i+1);
        //     int maxi=max(odd,even);
        //     if(maxi>end-start){
        //         start=i-(maxi-1)/2;
        //         end=i+maxi/2;
        //     }
        // }
        // return s.substr(start,end-start+1);
        int maxlen=0,sp=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(i,j,s,dp)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};