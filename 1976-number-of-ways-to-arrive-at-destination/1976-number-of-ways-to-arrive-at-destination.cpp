class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,1e18);
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>>q;
        q.push({0,0});
        while(!q.empty()){
            auto[cost,node]=q.top();
            q.pop();
            if(cost>dist[node]) continue;
            for(auto it:adj[node]){
                int edge=it.second,adjnode=it.first;
                if(edge+cost<dist[adjnode]){
                    dist[adjnode]=edge+cost;
                    q.push({edge+cost,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(edge+cost==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};