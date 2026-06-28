class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>hsh(1e6+2,0);
        vector<int> ans;
        for(int i:nums) hsh[i]++;
        for(int i:nums){
            if(hsh[i]==1 && (i==0||hsh[i-1]==0) && hsh[i+1]==0) ans.push_back(i);
        } 
        return ans;
    }
};