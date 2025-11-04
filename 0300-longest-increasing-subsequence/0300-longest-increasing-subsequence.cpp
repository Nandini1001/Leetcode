class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return helper(0,-1,nums,dp);
    }
    int helper(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int maxlen=helper(ind+1,prev,nums,dp);
        if(prev==-1 || nums[ind]>nums[prev]){
            maxlen=max(maxlen,1+helper(ind+1,ind,nums,dp));
        }
        return dp[ind][prev+1]=maxlen;
    }
};


//recursion

