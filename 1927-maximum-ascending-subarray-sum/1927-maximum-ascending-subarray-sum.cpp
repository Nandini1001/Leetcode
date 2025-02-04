class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=INT_MIN,i;
        /*int sum=0;
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
        return maxi=max(maxi,sum);*/
        int sum=nums[0];
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                sum+=nums[i];
            else
            {
                maxi=max(maxi,sum);
                sum=nums[i];
            }
            maxi=max(maxi,sum);
        }
        return max(maxi,sum);
    }
};