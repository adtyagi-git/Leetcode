class Disjointset{
vector<int>rank,parent;
public:
    Disjointset(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findparent(parent[node]);
    }

    void unionbyrank(int u,int v){
        int ul_u=findparent(u);
        int ul_v=findparent(v);
        if(ul_u==ul_v) return;
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v;
        }
        else if(rank[ul_u]>rank[ul_v]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjointset ds(n);
        unordered_map<string,int> mapindex;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mapindex.find(accounts[i][j])==mapindex.end()){
                    mapindex[accounts[i][j]]=i;
                }
                else{
                    ds.unionbyrank(i,mapindex[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>>mail(n);
        for(auto it:mapindex){
            string email=it.first;
            int parent=ds.findparent(it.second);
            mail[parent].push_back(email);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mail[i].empty()) continue;
            sort(mail[i].begin(), mail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<mail[i].size();j++){
                temp.push_back(mail[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};