class Solution {
private:
    int subarray(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        long long l=0,r=0,cnt=0,sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarray(nums,goal)-subarray(nums,goal-1);
    }
};