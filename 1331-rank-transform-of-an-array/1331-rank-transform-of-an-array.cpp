class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        vector<int>copy(arr.begin(),arr.end());
        sort(copy.begin(),copy.end());
        unordered_map<int,int> mpp;
        int j=1;
        int prev=copy[0];
        mpp[copy[0]]=j++;
        for(int i=1;i<copy.size();i++){
            if(copy[i]==prev){
                continue;
            }    
            else{
                prev=copy[i];
                mpp[copy[i]]=j++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;
        
    }
};