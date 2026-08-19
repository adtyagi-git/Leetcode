class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(discounts.begin(),discounts.end(),greater<int>());
        sort(prices.begin(),prices.end(),greater<int>());
        int n=prices.size(),m=discounts.size();
        int i=0,j=0;
        double sum=0;
        while(i<n && j<m){
            sum+=((prices[i]*(100-discounts[j]))/100.0);
            i++;j++;
        }
        while(i<n){
            sum+=prices[i];
            i++;
        }
        return sum;
    }
};