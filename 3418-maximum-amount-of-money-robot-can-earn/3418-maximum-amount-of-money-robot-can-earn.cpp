class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(), m=coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3,0)));
        if(coins[n-1][m-1]>=0){
            dp[n-1][m-1][0]=coins[n-1][m-1];
            dp[n-1][m-1][1]=coins[n-1][m-1];
            dp[n-1][m-1][2]=coins[n-1][m-1];
        }
        else{
            dp[n-1][m-1][0]=coins[n-1][m-1];
            dp[n-1][m-1][1]=0;
            dp[n-1][m-1][2]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 && j == m-1) continue;
                for(int neutralize=2; neutralize>=0; neutralize--){
                    if(coins[i][j]>=0){
                        int down=(i+1==n)?-1e8:dp[i+1][j][neutralize];
                        int rt=(j+1==m)?-1e8:dp[i][j+1][neutralize];
                        dp[i][j][neutralize]=coins[i][j]+max(rt, down);
                    }
                    else{
                        int down=(i+1==n)?-1e8:dp[i+1][j][neutralize];
                        int rt=(j+1==m)?-1e8:dp[i][j+1][neutralize];
                        int ifnoneutralize=coins[i][j]+max(rt, down);
                        int ifneutralize=INT_MIN;
                        if(neutralize){
                            int down=(i+1==n)?-1e8:dp[i+1][j][neutralize-1];
                            int rt=(j+1==m)?-1e8:dp[i][j+1][neutralize-1];
                            ifneutralize=max(rt, down);
                        }
                        dp[i][j][neutralize]=max(ifneutralize, ifnoneutralize);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
    int helper(vector<vector<int>>& coins, int i, int j, int neutralize, vector<vector<vector<int>>>& dp){
        if(i==coins.size()-1 && j==coins[0].size()-1){
            if(coins[i][j]>=0) return coins[i][j];
            if(neutralize) return 0;
            return coins[i][j];
        } 
        if(i==coins.size() || j==coins[0].size()) return -1e8;
        if(dp[i][j][neutralize]!=-1) return dp[i][j][neutralize];
        if(coins[i][j]>=0){
            return coins[i][j]+max(helper(coins,i+1, j, neutralize, dp), helper(coins, i, j+1, neutralize, dp));
        }
        int ifnoneutralize=coins[i][j]+max(helper(coins,i+1, j, neutralize, dp), helper(coins, i, j+1, neutralize, dp));
        int ifneutralize=INT_MIN;
        if(neutralize){
            ifneutralize=max(helper(coins,i+1, j, neutralize-1, dp), helper(coins, i, j+1, neutralize-1, dp));
        }
        return dp[i][j][neutralize]=max(ifneutralize, ifnoneutralize);
    }
};