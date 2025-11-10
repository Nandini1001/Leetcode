class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        int c=grid[n-1][m-1]?1:0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        //for(int cost=0;cost<=k;cost++) dp[0][0][cost]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int cost=k;cost>=0;cost--){
                    if(i==0 && j==0){
                        dp[0][0][cost]=grid[0][0];
                        continue;
                    }
                    int c=grid[i][j]?1:0;
                    int up=-1e9;
                    if(i-1>=0 && cost+c<=k) up=grid[i][j]+dp[i-1][j][cost+c];
                    int left=-1e9;
                    if(j-1>=0 && cost+c<=k)left=grid[i][j]+dp[i][j-1][cost+c];
                    dp[i][j][cost]=max(up,left);
                }
            }
        }
        int ans=dp[n-1][m-1][0];
        return (ans<=-1e8)?-1:ans;
    }
};

//tabulation