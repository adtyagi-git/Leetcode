class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8) return n;
        int first=n/8;
        int second=n%8;
        int push=0,i=1;
        while(first--){
            push+=(8*i);
            i++;
        }
        while(second--){
            push+=i;
        }
        return push;
    }
};