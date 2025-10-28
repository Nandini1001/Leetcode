class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1, prices, 2,dp);
    }
    int helper(int ind, int buy, vector<int>& prices, int cnt, vector<vector<vector<int>>>& dp){
        if(ind==prices.size() || cnt==0) return 0;
        if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];
        int profit=INT_MIN;
        if(buy){
            profit=max(-prices[ind]+helper(ind+1,0,prices,cnt,dp),helper(ind+1,1,prices,cnt,dp));
        }
        else{
            profit=max(prices[ind]+helper(ind+1,1,prices,cnt-1,dp),helper(ind+1,0,prices,cnt,dp));
        }
        return dp[ind][buy][cnt]=profit;
    }
};


//memoization
//1->buy
//0->not buy