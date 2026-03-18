class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        if(grid[0][0]>k) return 0;
        int cnt=0;
        vector<vector<int>> presum(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0) presum[i][j]+=presum[i-1][j];
                if(j!=0) presum[i][j]+=presum[i][j-1];
                presum[i][j]+=grid[i][j];
                if(i != 0 && j != 0) presum[i][j] -= presum[i-1][j-1];
                if(presum[i][j]<=k) cnt++;
            }
        }
        return cnt;
    }
};