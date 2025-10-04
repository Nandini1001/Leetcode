class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxarea=INT_MIN;
        while(l<r){
            if(height[l]<=height[r]){
                maxarea=max(maxarea, height[l]*(r-l));
                l++;
            }
            else
            {
                maxarea=max(maxarea, height[r]*(r-l));
                r--; 
            }
        }
        return maxarea;
    }
    
};