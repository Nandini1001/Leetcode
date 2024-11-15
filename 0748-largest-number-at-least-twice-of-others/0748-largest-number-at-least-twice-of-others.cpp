class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=*max_element(nums.begin(),nums.end());
        int n=nums.size(),ind;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==max)
                 ind=i;
            else if(2*nums[i]>max)
                return -1;
        }
        return ind;
    }
};