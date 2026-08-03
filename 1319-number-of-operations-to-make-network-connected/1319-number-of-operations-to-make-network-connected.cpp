class Disjointset{
    vector<int>rank,parent;
public:
    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent[node]);
    }

    void unionbyrank(int u,int v){
        int ul_u=findparent(u),ul_v=findparent(v);
        if(ul_u==ul_v) return;
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v;
        }
        else if(rank[ul_v]<rank[ul_u]){
            parent[ul_v]=ul_u;
        }
        else{
            parent[ul_v]=ul_u;
            rank[ul_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int countextra=0,counthead=0;
        for(auto it:connections){
            if(ds.findparent(it[0])==ds.findparent(it[1])) countextra++;
            else{
                ds.unionbyrank(it[0],it[1]);
            }
        }

        for(int i=0;i<n;i++){
            if(ds.findparent(i)==i) counthead++;
        }
        int ans=counthead-1;
        if(countextra>=ans) return ans;
        return -1;
    }
};