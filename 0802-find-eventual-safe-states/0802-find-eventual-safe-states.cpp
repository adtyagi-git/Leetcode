class Solution {
private:
    bool dfs(int node,vector<int>&path,vector<int>&vis,vector<int>&check,vector<vector<int>>& graph){
        vis[node]=1;
        path[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,path,vis,check,graph)){
                    return true;
                }
            }
            else if(path[it]){
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>vis(v,0),path(v,0),check(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]) dfs(i,path,vis,check,graph);
        }
        vector<int>ans;
        for(int i=0;i<v;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};