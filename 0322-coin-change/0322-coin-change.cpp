class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int ans=helper(coins.size()-1, amount, coins,dp);
        return ans==1e9?-1:ans;
    }
    int helper(int ind, int tar, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            if(tar%coins[0]==0) return tar/coins[0];
            else return 1e9;
        }
        if(dp[ind][tar]!=-1)  return dp[ind][tar];
        int nottake=helper(ind-1,tar,coins,dp);
        int take=INT_MAX;
        if(coins[ind]<=tar)
            take=1+helper(ind,tar-coins[ind],coins,dp);
        return dp[ind][tar]=min(take,nottake);
    }
};

//memoization