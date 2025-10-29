class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1, prices,dp, fee);
    }
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=INT_MIN;
        if(buy){
            profit=max(-prices[ind]+helper(ind+1,0,prices,dp, fee),helper(ind+1,1,prices,dp,fee));
        }
        else{
            profit=max(prices[ind]-fee+helper(ind+1,1,prices,dp,fee),helper(ind+1,0,prices,dp,fee));
        }
        return dp[ind][buy]=profit;
    }
};


//memoization
//1->buy
//0->not buy
//either can apply fees in buy or sell
