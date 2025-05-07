class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return function(n,dp);
    }
    int function(int n, vector<int> &dp)
    {
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int left=function(n-1,dp);
        int right=function(n-2,dp);
        return dp[n]=left+right;
    }
};