class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int mn=INT_MAX,mx=0;
        for(int i:nums){
            if(mx<i){
                mx=i;
            }
            if(mn>i){
                mn=i;
            }
            st.insert(i);
        }
        
        vector<int>ans;
        for(int i=mn;i<=mx;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};