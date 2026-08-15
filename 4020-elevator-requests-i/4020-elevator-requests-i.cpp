class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time=0;
        int present=0;
        for(int i=0;i<requests.size();i++){
            time+=abs(requests[i]-present);
            present=requests[i];
        }
        return time;
    }
};