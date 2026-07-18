class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=1e9,maxi=-1;
        for(int i:nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        return gcd(mini,maxi);
    }
};