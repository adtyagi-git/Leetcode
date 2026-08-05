class Disjointset{
public:
    vector<int>size,parent;
    Disjointset(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulu=findparent(u);
        int ulv=findparent(v);
        if(ulu==ulv) return;
        if(size[ulv]<size[ulu]){
            parent[ulv]=ulu;
            size[ulu]+=size[ulv];
        }
        else{
            parent[ulu]=ulv;
            size[ulv]+=size[ulu];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        int m=grid.size(),n=grid[0].size();
        Disjointset ds(m*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        int curele=n*i+j;
                        int adjele=n*nr+nc;
                        ds.unionbysize(curele,adjele);
                    }
                }
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                unordered_set<int>components;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        components.insert(ds.findparent(n*nr+nc));
                    }
                }
                int size=1;
                for(auto it:components){
                    size+=ds.size[it];
                }
                mx=max(mx,size);
            }
        }
        for(int node=0;node<m*n;node++){
            mx=max(mx,ds.size[ds.findparent(node)]);
        }
        return mx;
    }
};