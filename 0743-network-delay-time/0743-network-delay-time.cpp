class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>time(n+1,1e9);
        time[k]=0;
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            auto[currtime,node]=q.top();
            q.pop();
            if(currtime>time[node]) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edge=it.second;
                if(edge+currtime<time[adjnode]){
                    time[adjnode]=edge+currtime;
                    q.push({edge+currtime,adjnode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(time[i]==1e9) return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
        
    
    
};