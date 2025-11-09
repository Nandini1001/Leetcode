class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        int c=grid[n-1][m-1]?1:0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=helper(n-1,m-1,0,k,grid,dp);
        return (ans<=-1e8)?-1:ans;
    }
    int helper(int i, int j, int cost, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(cost>k) return INT_MIN;
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return INT_MIN;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j][cost]!=-1) return dp[i][j][cost];
        int c=grid[i][j]?1:0;
        int up=grid[i][j]+helper(i-1,j,cost+c,k,grid,dp);
        int left=grid[i][j]+helper(i,j-1,cost+c,k,grid,dp);
        return dp[i][j][cost]=max(up,left);
    }
};

//first error is bcos of recursion
//second error is bcos i forget to assign correct size to dp
//third and fourth error is bcos in 8 line i was using specific values like -2147483644 instead of -1e8