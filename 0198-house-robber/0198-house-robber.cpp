class Solution {
public:
    int fun(int ind, vector<int> nums, vector<int>& dp){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+fun(ind-2,nums,dp);
        int notpick=fun(ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int ind=1;ind<n;ind++){
            int pick=nums[ind];
            if(ind!=1)
                pick=pick+dp[ind-2];
            int notpick=dp[ind-1];
            dp[ind]=max(pick,notpick);
        }
        return dp[n-1];
    }
};