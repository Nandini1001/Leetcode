class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=0;
        int zeros=0, maxlen=0;
        while(high<nums.size())
        {
            if(nums[high]==0) zeros++;
            if(zeros>k)
            {
                if(nums[low]==0)
                    zeros--;
                low++;
            }
            if(zeros<=k)
                maxlen=max(maxlen,high-low+1);
            high++;
        }
        return maxlen;
    }
};