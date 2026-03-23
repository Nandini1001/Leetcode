class Solution {
public:
    int mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<pair<long long, long long>>> dp(n,vector<pair<long long, long long>>(m,{LLONG_MIN,LLONG_MAX}));
        auto it=helper(n-1,m-1,grid,dp);
        return (it.first<0)?-1:(it.first)%mod;
    } 
    pair<long long, long long> helper(int i, int j, vector<vector<int>>& grid, 
    vector<vector<pair<long long, long long>>>& dp){
        if(i==0 && j==0) return {grid[0][0],grid[0][0]};
        if(dp[i][j]!=make_pair(LLONG_MIN,LLONG_MAX)) return dp[i][j];
        long long maxval=LLONG_MIN, minval=LLONG_MAX;
        if(j-1>=0) {
            auto it=helper(i,j-1,grid,dp);
            long long one=it.first*grid[i][j];
            long long sec=it.second*grid[i][j];
            maxval=max({maxval,one,sec});
            minval=min({minval,one,sec});
        }
        
        if(i-1>=0){
            auto it=helper(i-1,j,grid,dp);
            long long one=it.first*grid[i][j];
            long long sec=it.second*grid[i][j];
            maxval=max({maxval,one,sec});
            minval=min({minval,one,sec});
        } 
        return dp[i][j]={maxval,minval};
    }
};