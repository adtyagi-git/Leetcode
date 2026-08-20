class Solution {
public:
    int countValidPrefixes(string s) {
        int count=0,count0=0,count1=0;
        for(auto i:s){
            if(i-'0'== 0){
                count0++;
            }
            if(i-'0'==1){
                count1++;
            }
            if(count0==count1 || abs(count1-count0)==1){
                count++;
            }
        }
        return count;
    }
};