class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n-1 && nums[i]==nums[i + 1]) {
            i++;
        }
        if(i==n - 1)
            return true;
            
        if(nums[i]<=nums[i+1]){
            for(int i=1;i<n-1;i++){
                if(nums[i+1]<nums[i]) return false;
            }
            return true;
        }
        else{
            for(int i=1;i<n-1;i++){
                if(nums[i+1]>nums[i]) return false;
            }
            return true;
        }
    }
};