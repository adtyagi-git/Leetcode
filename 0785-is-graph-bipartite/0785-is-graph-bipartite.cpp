class Solution {
private:
    bool dfs(int node,int colour,vector<vector<int>> &graph,vector<int>&vis){
        vis[node]=colour;
        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(dfs(it,!colour,graph,vis)==false) return false;
            }
            else if(colour==vis[it]){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int>vis(m,-1);
        for(int i=0;i<m;i++){
            if(vis[i]==-1){
                if(!dfs(i,0,graph,vis)) return false;
            }
        }
        return true;
    }
};