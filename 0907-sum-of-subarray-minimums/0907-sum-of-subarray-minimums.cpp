class Solution {
private:
    vector<int>findprevsmall(vector<int>& arr){
        vector<int>ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findnextsmall(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>presmall=findprevsmall(arr);
        vector<int>nextsmall=findnextsmall(arr);
        int n=arr.size(),total=0;
        for(int i=0;i<n;i++){
            int left=i-presmall[i];
            int right=nextsmall[i]-i;
            total=(total+(left*right*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};