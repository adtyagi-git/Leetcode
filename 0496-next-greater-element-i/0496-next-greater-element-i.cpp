class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size());
        int n=nums2.size()-1;
        stack<int> st;
        while(n>=0){
                while(!st.empty() && nums2[n]>=st.top() ){
                    st.pop();
                }
                if(st.empty()) ans[n]=-1;
                else ans[n]=st.top();
                st.push(nums2[n]);
                n--;
        }        
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;;
        }
        vector<int> result;
        for(int j=0;j<nums1.size();j++){
            result.push_back(ans[mp[nums1[j]]]);
        }
        return result;
    }
};