class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            int diff=pq.top().first;
            auto[r,c]=pq.top().second;
            pq.pop();
            if(r == m-1 && c == n-1) return diff;
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int effort=max(abs(heights[r][c]-heights[nr][nc]),diff);
                    if(effort<dist[nr][nc]){
                        dist[nr][nc]=effort;
                        pq.push({effort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};