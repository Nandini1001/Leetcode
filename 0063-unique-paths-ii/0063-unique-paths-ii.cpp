class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]) return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(m-1, n-1, obstacleGrid, dp);
    }
    int helper(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(obstacleGrid[i][j]) return dp[i][j]=0;
        return dp[i][j]=helper(i, j-1, obstacleGrid, dp) + helper(i-1, j, obstacleGrid, dp);
    }
};