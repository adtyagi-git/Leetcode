class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int l=0,r=height.size()-1;
        while(l<r){
            int currarea=min(height[l],height[r])*(r-l);
            area=max(area,currarea);
            if(height[l]>height[r]) r--;
            else l++;
        }
        return area;
    }
};