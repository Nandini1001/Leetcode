class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int k=1;
        while(1)
        {
            if(mpp[k]==0)
            {
                return k;
            }
            k++;
        }*/
        int i,n=nums.size();
        for(i=0;i<n;i++)
        {
            if(nums[i]>0 && nums[i]<=n && nums[i]!=i+1)
            {
                if(nums[nums[i]-1]!=nums[i])
                {int temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
                i--;}
            }
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};