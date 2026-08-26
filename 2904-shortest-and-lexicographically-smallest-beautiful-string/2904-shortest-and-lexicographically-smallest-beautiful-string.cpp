class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        int l=0,r=0,n=s.size();
        int count=0;
        int len=INT_MAX;
        while(r<n){
            if(s[r]=='1') count++;
            while(count>k){
                if(s[l]=='1') count--;
                l++;
            }
            if(count==k){
                while(s[l]=='0') l++;
                string curr=s.substr(l,r-l+1);
                if(curr.size()<len || (curr.size()==len && curr<ans)){
                    len=r-l+1;
                    ans=curr;
                }
            }
            r++;
        }
        return ans;
    }
};