class Solution {
private:
    bool check(string a,string b){
        int count=1;
        if(a.size()+1!=b.size()) return false;
        int j=0;
        int i=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                j++;
                i++;
            }    
            else{
                if(count==0) return false;
                count--;
                j++;
            }
        }
        return true;
    }
    static bool comp(string a,string b){
        if(b.size()>a.size()) return true;
        return false;
    } 
     
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j],words[i]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
                maxi=max(maxi,dp[i]);
            }
        }
        return maxi;
    }
};