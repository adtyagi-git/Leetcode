class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<>());
        int i=0,n=word.size();
        int push=0;
        while(i<26){
            if(freq[i]==0) break;
            if(i<8){
                push+=freq[i]*1;
            }
            else if(i>=8 && i<16){
                push+=freq[i]*2;
            }
            else if(i>=16 && i<24){
                push+=freq[i]*3;
            }
            else push+=freq[i]*4;
            i++;
        }
        return push;
    }
    
};