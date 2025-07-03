class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum=0;
        for(int it:nums) 
            totsum+=it;
        if(totsum-target<0 || (totsum-target)%2) return false;
        target=(totsum-target)/2;
        vector<int> prev(target+1,0), cur(target+1,0);
        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;
        if(nums[0]!=0 && nums[0]<=target) prev[nums[0]]=1;
        for(int ind=1;ind<nums.size();ind++){
            for(int sum=0;sum<=target;sum++){
                int nottake=prev[sum];
                int take=0;
                if(nums[ind]<=sum) take=prev[sum-nums[ind]];
                cur[sum]=take+nottake;
            }
            prev=cur;
        }
        return prev[target];
    }
};