class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount+1,0), cur(amount+1,0);
        for(int tar=0;tar<=amount;tar++) 
        {
            if(tar%coins[0]==0) prev[tar]=tar/coins[0];
            else prev[tar]=1e9;
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int tar=0;tar<=amount;tar++){
                int nottake=prev[tar];
                int take=INT_MAX;
                if(coins[ind]<=tar) take=1+cur[tar-coins[ind]];
                cur[tar]=min(take,nottake);
            }
            prev=cur;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};