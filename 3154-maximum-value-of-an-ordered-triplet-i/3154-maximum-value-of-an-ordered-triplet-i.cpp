class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long max_val=LONG_MIN;
        long long maxi=nums[0];
        long long maxdiff=LONG_MIN;
        for(int i=1;i<nums.size()-1;i++)
        {
            maxdiff=max(maxdiff,maxi-nums[i]);
            max_val=max(max_val,maxdiff*nums[i+1]);
            maxi=max(maxi,(long long)(nums[i]));
        }
        return max_val>=0?max_val:0;
    }
};