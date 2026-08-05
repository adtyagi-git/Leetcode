class Solution {
private:
    void dfs(int node,vector<int> &vis,vector<vector<int>>&graph){
        vis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(it,vis,graph);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>graph(n);
        vector<int> vis(n,0);
        for(auto it:invocations){
            graph[it[0]].push_back(it[1]);
        }
        dfs(k,vis,graph);
        vector<int>ans;
        for(auto it:invocations){
            if(!vis[it[0]] && vis[it[1]]){
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};