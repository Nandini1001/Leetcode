class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        //vector<int> new=nums;
        //if(sorted(nums)) return 0;
        while(!sorted(nums))
            {
                int minsum=INT_MAX, maxind=-1;
                for(int i=0;i<nums.size()-1;i++)
                    {
                        if(nums[i]+nums[i+1]<minsum)
                        {
                            minsum=nums[i]+nums[i+1];
                            maxind=i;
                        }
                    }
                /*vector<int> neww;
                for(int i=0;i<nums.size();i++)
                    {
                        if(i==maxind)
                        {
                            neww.push_back(nums[i]+nums[i+1]);
                            i++;
                        }
                        else
                            neww.push_back(nums[i]);
                    }
                nums=neww;*/
                nums[maxind]=nums[maxind]+nums[maxind+1];
                nums.erase(nums.begin()+maxind+1);
                cnt++;
            }
        return cnt;
    }
    bool sorted(vector<int> &nums)
{
    for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
                return false;
        }
    return true;
}
    
};