class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxval=LONG_MIN;
        int maxi=nums[0];
        long long maxdiff=LONG_MIN;
        for(int i=1;i<nums.size()-1;i++)
        {
            maxdiff=max(maxdiff,(long long)(maxi-nums[i]));
            maxval=max(maxval,maxdiff*nums[i+1]);
            maxi=max(maxi,nums[i]);
        }
        return maxval<0?0:maxval;
    }
};