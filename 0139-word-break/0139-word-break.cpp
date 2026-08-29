class Solution {
private:
    bool isindict(string check,vector<string>& wordDict){
        for(string i:wordDict){
            if(i==check) return true;
        }
        return false;
    }

    bool rec(int index,string s,vector<string>& wordDict,vector<int>&dp){
        if(index==s.size()){
            return true;
        }
        if(dp[index]!=-1) return dp[index];
        for(int j=index;j<s.size();j++){
            if(isindict(s.substr(index,j-index+1),wordDict)){
                if(dp[index]=rec(j+1,s,wordDict,dp)){
                    return true;
                }
            } 
        }
        return dp[index]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return rec(0,s,wordDict,dp);
    }
};