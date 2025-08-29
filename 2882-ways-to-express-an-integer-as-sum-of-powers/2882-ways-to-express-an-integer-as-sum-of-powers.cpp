class Solution {
public:
    int sumPower(int i, int sum, int power, vector<vector<int>> &dp){
        int mod=(int)1e9+7;
        if(sum==0) return 1;
        if(pow(i,power)>sum) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=sumPower(i+1,sum-pow(i,power),power,dp);
        int nottake=sumPower(i+1,sum,power,dp);
        return dp[i][sum]=(take+nottake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+2,vector<int>(n+1,-1));
        return sumPower(1,n,x,dp);
        //tabulation not working
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=n;i>=1;i--){
            for(int j=n;j>=1;j--){
                if(pow(i,x)>j){
                    dp[i][j]=0;
                    continue;
                }
                int take=dp[i+1][j-pow(i,x)];
                int nottake=dp[i+1][j];
                dp[i][j]=take+nottake;
            }
        }
        return dp[1][n];
    }
};