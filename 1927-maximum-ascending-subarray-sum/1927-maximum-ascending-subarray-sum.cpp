class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=INT_MIN,sum=0,i;
        for(i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
                sum+=nums[i];
            else
            {
                sum+=nums[i];
                maxi=max(maxi,sum);
                sum=0;
            }
        }
        sum+=nums[i];
        return maxi=max(maxi,sum);
    }
};