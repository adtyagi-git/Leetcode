class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int maxi=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int maxindex=-1,miniindex=-1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi) maxindex=i;
            if(nums[i]==mn) miniindex=i;
        }

        int left = max(maxindex, miniindex) + 1;
        int right = n - min(maxindex, miniindex);
        int mixed1 = maxindex + 1 + (n - miniindex);
        int mixed2 = miniindex + 1 + (n - maxindex);

        return min({left, right, mixed1, mixed2});
    }
};