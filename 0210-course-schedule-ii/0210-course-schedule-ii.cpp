class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int n=numCourses;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ind(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }

        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};