class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0],b=nums[nums.size()-1];
        return gcd(a,b);
    }
};