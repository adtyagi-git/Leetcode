class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int y=n;
        while(n>0){
            sum+=(n%10);
            prod*=(n%10);
            n/=10;
        }
        return y%(sum+prod)==0;
    }
};