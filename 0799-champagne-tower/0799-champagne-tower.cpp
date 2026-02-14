class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double>(query_row+1,-1));
        return min(1.0,helper(poured,query_row, query_glass,dp));
    }
    double helper(int poured, int i, int j, vector<vector<double>>& dp){
        if(j==-1 || i<j) return 0;
        if(i==0) return poured;
        if(dp[i][j]!=-1) return dp[i][j];
        double left=helper(poured,i-1,j-1,dp);
        left=((left-1)<0)?0:(left-1)/2.0;
        double right=helper(poured,i-1,j,dp);
        right=((right-1)<0)?0:(right-1)/2.0;
        return dp[i][j]=left+right;
    }
};