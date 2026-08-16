class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=INT_MAX;
        int a=INT_MAX;
        for(auto it=0; it<drones.size(); it++){
            int x = drones[it][0];
            int y = drones[it][1];
            int range = drones[it][2];
            int value = abs(target[0] - x) + abs(target[1]-y);
            if(value <= range && value < a){
                a=value;
                ans=it;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};