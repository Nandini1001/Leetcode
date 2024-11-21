class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size(), cnt=0, ans=INT_MAX, maxcnt=0;
        for(int i=0;i<n;i++)
        {
            cnt=0;
            if(nums[i]%2==0)
            {
                for(int j=0;j<n;j++)
                {
                    if(nums[j]%2==0)
                    {
                        if(nums[i]==nums[j])
                            cnt++;
                    }
                }
                if(cnt>maxcnt)
                {
                    maxcnt=cnt;
                    ans=nums[i];
                }
                else if(cnt==maxcnt)
                {
                    ans=min(ans,nums[i]);
                }
            }
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};