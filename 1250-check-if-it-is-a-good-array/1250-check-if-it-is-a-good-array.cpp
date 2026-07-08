class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int Gcd=nums[0];
        for(int i:nums){
            Gcd=gcd(Gcd,i);
        }
        return Gcd==1;
    }
};