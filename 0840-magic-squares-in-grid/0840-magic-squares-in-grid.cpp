class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int cnt=0;
        for(int i=0;i+2<n;i++){
            for(int j=0;j+2<m;j++){
                cnt+=solve(grid,i,j);
            }
        }
        return cnt;
    }
    int solve(vector<vector<int>>& g, int row, int col){
        vector<int> numbers(10,0);
        for(int r=row; r<row+3;r++){
            for(int c=col; c<col+3; c++){
                if(g[r][c]<1 || g[r][c]>9 || numbers[g[r][c]]) return 0;
                else numbers[g[r][c]]=1;
            }
        }
        for(int i = 0; i < 3; i++) {
            if(g[row+i][col] + g[row+i][col+1] + g[row+i][col+2] != 15)
                return 0;
            if(g[row][col+i] + g[row+1][col+i] + g[row+2][col+i] != 15)
                return 0;
        }
        if(g[row][col] + g[row+1][col+1] + g[row+2][col+2] != 15)
            return 0;
        if(g[row][col+2] + g[row+1][col+1] + g[row+2][col] != 15)
            return 0;
        return 1;
    }
};