class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int>freq(101,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int count=1;
        int element=nums[0];
        int special=0;
        for(int i=1;i<n;i++){
            if(nums[i]==element){
                count++;
            }
            else{
                if(count==freq[element]) special++;
                element=nums[i];
                count=1;
            }
        }
        if(count==freq[element]) special++;
        return special;
    }
};