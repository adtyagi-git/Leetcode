class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,sindex=-1,minlen=INT_MAX,count=0;
        unordered_map<char,int> mp;
        for(char ch:t) mp[ch]++;
        while(r<s.size()){
            if(mp[s[r]]>0){
                count++;
            }
            mp[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};