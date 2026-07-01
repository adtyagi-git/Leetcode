class Solution {
private:
    int findlongrect(vector<int>arr){
        int n=arr.size(),maxarea=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int element=st.top();st.pop();
                int pse=st.empty()?-1:st.top();
                int nse=i;
                maxarea=max(maxarea,arr[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int element=st.top();
            st.pop();
            int nse=n,pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,arr[element]*(nse-pse-1));
        }
        return maxarea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> presum(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum=0;
                presum[i][j]=sum;
            }
        }
        int total=0;
        for(int i=0;i<presum.size();i++){
            total=max(total,findlongrect(presum[i]));
        }
        return total;
    }
};