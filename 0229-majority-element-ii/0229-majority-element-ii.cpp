class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0,ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
            else if(count1==0){
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0){
                count2=1;
                ele2=nums[i];
            }
            else{
                count1--;count2--;
            }
        }
        count1=0;count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
        }
        int n=nums.size();
        vector<int>ans;
        if(count1>(n/3)) ans.push_back(ele1);
        if(count2>(n/3)) ans.push_back(ele2);
        return ans;
    }
};