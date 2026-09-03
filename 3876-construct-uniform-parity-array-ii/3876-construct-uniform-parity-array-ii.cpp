class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestodd=INT_MAX;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2){
                smallestodd=min(smallestodd,nums1[i]);
            }
        }
        if(smallestodd==INT_MAX) return true;
        for(int i:nums1){
            if(i%2==0 && i<smallestodd){
                return false;
            }
        }
        return true;
    }
};