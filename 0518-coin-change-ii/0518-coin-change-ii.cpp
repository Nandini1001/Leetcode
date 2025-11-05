class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned long long>> dp(coins.size(),vector<unsigned long long>(amount+1,0));
        for(int tar=0;tar<=amount;tar++){
            if(tar%coins[0]==0) dp[0][tar]=1;
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int tar=0;tar<=amount;tar++){
                unsigned long long nottake=dp[ind-1][tar];
                unsigned long long take=0;
                if(coins[ind]<=tar)
                    take=dp[ind][tar-coins[ind]];
                dp[ind][tar]=take+nottake;
            }
        }
        return (int)dp[coins.size()-1][amount];
    }
    
};