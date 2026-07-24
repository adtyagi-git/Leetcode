class Solution {
private:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int m=grid.size(),n=grid[0].size();
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && grid[nx][ny]=='1'){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};