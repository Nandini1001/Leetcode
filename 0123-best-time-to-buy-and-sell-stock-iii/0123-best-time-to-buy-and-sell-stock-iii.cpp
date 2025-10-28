class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
                for(int cnt=1;cnt<=2;cnt++){
                    dp[ind][1][cnt]=max(-prices[ind]+dp[ind+1][0][cnt],dp[ind+1][1][cnt]);
                    dp[ind][0][cnt]=max(prices[ind]+dp[ind+1][1][cnt-1],dp[ind+1][0][cnt]);
                }
            }
        return dp[0][1][2];
    }
};


//another way of tabulation by removing buy loop
//1->buy
//0->not buy