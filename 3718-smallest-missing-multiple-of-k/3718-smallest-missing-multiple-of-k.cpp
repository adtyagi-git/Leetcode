class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int i:nums){
            st.insert(i);
        }
        int i=1;
        int num=k;
        while(st.count(num)){
            i++;
            num=k*i;
        }
        return num;
    }
};