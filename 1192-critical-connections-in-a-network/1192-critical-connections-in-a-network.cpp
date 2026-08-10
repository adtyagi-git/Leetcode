class Solution {
private:
    int timer=1;
private:
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&low,vector<int>&tin,vector<int>&vis,vector<vector<int>>&bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,low,tin,vis,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>tin(n,0),low(n,0),vis(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,low,tin,vis,bridges);
        return bridges;
    }
};