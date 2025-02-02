class Solution {
private:
    double sumofdivisor(vector<int>& nums,int divisor)
    {
        double sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=ceil(double(nums[i])/double(divisor));
        return sum;
    }
    int findMax(vector<int>& nums)
    {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
            maxi=max(maxi,nums[i]);
        return maxi;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=0,high=findMax(nums);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(sumofdivisor(nums,mid)<=threshold)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};