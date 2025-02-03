class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int inc=1,dec=1,maxinc=1,maxdec=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                inc++;
                maxdec=max(dec,maxdec);
                dec=1;
            }
            else if(nums[i]<nums[i-1])
            {
                dec++;
                maxinc=max(maxinc,inc);
                inc=1;
            }
            else
            {
                maxdec=max(dec,maxdec);
                dec=1; 
                maxinc=max(maxinc,inc);
                inc=1;  
            }
        }
        maxdec=max(dec,maxdec);
        maxinc=max(maxinc,inc);
        return max(maxinc,maxdec);
    }
};