class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        stack<int>st;
        int n=asteroids.size();
        while(i<n){
            while(i<n && !st.empty() && asteroids[i]<0 && st.top()>0){
                if(st.top()<abs(asteroids[i])) st.pop();
                else if(st.top()>abs(asteroids[i])) i++;
                else{
                    st.pop();i++;
                }
            }
            if(i<n)st.push(asteroids[i]);
            i++;
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};