class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string res=s.substr(0,n/2);
        sort(res.begin(),res.end());
        string rev=res;
        reverse(rev.begin(),rev.end());
        if(n%2==1){
            return res+s.substr(n/2,1)+rev;
        }
        else return res+rev;
    }
};