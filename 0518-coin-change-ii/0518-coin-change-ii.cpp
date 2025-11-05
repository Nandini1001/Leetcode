class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins.size()-1, amount, coins,dp);
        return ans;
    }
    int helper(int ind, int tar, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            return tar%coins[0]==0;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int nottake=helper(ind-1,tar,coins,dp);
        int take=0;
        if(coins[ind]<=tar)
            take=helper(ind,tar-coins[ind],coins,dp);
        return dp[ind][tar]=take+nottake;
    }
};