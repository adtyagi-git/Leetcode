class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>res;
            int curr=1;
            res.push_back(curr);
            for(int col=1;col<i;col++){
                curr*=(i-col);
                curr/=col;
                res.push_back(curr);
            }
            ans.push_back(res);
        }
        return ans;
    }
};