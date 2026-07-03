class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int longest=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x++;count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};