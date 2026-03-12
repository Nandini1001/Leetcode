class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[mid]==1) mid++;
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else{
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
        }
    }
};