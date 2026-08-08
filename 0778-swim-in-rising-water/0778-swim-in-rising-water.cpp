class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        int n=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        while(!pq.empty()){
            auto[elevation,point]=pq.top();
            pq.pop();
            int r=point.first;
            int c=point.second;
            if(r==n-1 && c==n-1) return elevation;
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    pq.push({max(elevation,grid[nr][nc]),{nr,nc}});
                }
            }
        }
        return -1;
    }
};