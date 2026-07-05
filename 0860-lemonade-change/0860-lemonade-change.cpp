class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int count5=0,count10=0;
        int i=0;
        while(i<n){
            if(bills[i]==5) count5++;
            else if(bills[i]==10){
                if(count5>0){
                    count5--;count10++;
                }
                else return false;
            }
            else{
                if(count10>0 && count5>0){
                    count5--;count10--;
                }
                else if(count5>=3) count5-=3;
                else return false;
            }
            i++;
        }
        return true;
    }
};