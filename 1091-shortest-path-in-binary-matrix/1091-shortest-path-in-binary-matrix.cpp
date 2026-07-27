class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        int dx[8]={0,0,-1,1,1,-1,1,-1};
        int dy[8]={-1,1,0,0,-1,1,1,-1};
        while(!q.empty()){
            auto[x,y]=q.front().first;
            int dis=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && 1+dis<dist[nx][ny]){
                    dist[nx][ny]=1+dis;
                    if(nx==n-1 && ny==n-1) return dis+1;
                    q.push({{nx,ny},dis+1});
                }
            }
        }
        return -1;
    }
};