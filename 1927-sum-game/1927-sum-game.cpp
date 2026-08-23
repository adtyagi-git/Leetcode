class Solution {
public:
    bool sumGame(string num) {
        int leftsum=0,rightsum=0;
        int leftques=0,rightques=0;
        int n=num.size();
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    leftques++;
                }
                else{
                    rightques++;
                }
            }
            else{
                if(i<n/2){
                    leftsum+=num[i]-'0';
                }
                else{
                    rightsum+=num[i]-'0';
                }
            }
        }
        int totalques=leftques+rightques;
        if(totalques%2==1){
            return true;
        }
        else{
            int left=2*leftsum+9*leftques;
            int right=2*rightsum+9*rightques;
            return left!=right;
        }
    }
};