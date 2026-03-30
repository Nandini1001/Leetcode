class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int l=0, r=height.size()-1;
        int pge=0, nge=0;
        while(l<=r){
            if(height[l]<height[r]){
                water=water+max(0,pge-height[l]);
                pge=max(pge, height[l]);
                l++;
            }
            else{
                water=water+max(0,nge-height[r]);
                nge=max(nge, height[r]);
                r--;
            }
        }
        return water;
    }
};