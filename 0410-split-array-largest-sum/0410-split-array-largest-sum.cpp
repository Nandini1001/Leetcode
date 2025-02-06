class Solution {
private:
    int noofsubarray(vector<int>& nums, int maxsum)
    {
        int cnt=1,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]<=maxsum)
                sum+=nums[i];
            else 
            {
                cnt++;
                sum=nums[i];
            }
        }
        return cnt;
    }
    int maximum(vector<int>& nums)
    {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    int sum(vector<int>& nums)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        return sum;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=maximum(nums),high=sum(nums);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(noofsubarray(nums,mid)>k)
                low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};