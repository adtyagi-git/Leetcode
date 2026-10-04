class Solution {
public:
    int minRotations(string s) {
        int count=min((s[0]-'0'),10-(s[0]-'0'));
        for(int i=1;i<s.size();i++){
            int d=abs((s[i]-'0')-(s[i-1]-'0'));
            count+=min(d,10-d);
        }
        return count;
    }
};