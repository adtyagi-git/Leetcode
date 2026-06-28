class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>hsh;
        vector<int> ans;
        for(int i:nums) hsh[i]++;
        for(int i:nums){
            if(hsh[i]==1 && hsh[i-1]==0 && hsh[i+1]==0) ans.push_back(i);
        } 
        return ans;
    }
};