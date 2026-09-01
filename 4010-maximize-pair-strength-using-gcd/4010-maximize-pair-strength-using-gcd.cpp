class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long maxi=LLONG_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long formula=(1LL*nums[i]*nums[j])/(1LL*gcd(nums[i],nums[j])*gcd(nums[i],nums[j]));
                maxi=max(maxi,formula);
            }
        }
        return maxi;
    }
};