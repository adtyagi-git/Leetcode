class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            auto[node,cost]=q.front().second;
            q.pop();
            if(stops>k+1) continue;
            for(auto it:adj[node]){
                int cos=it.second;
                int adjnode=it.first;
                if(stops<=k && cos+cost<dist[adjnode]){
                    dist[adjnode]=cos+cost;
                    q.push({stops+1,{adjnode,cost+cos}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};