class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> sum(n, vector<int>(m, 0));
        vector<vector<int>> xcnt(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                int isX = (grid[i][j] == 'X');

                sum[i][j] = val;
                xcnt[i][j] = isX;

                if(i > 0){
                    sum[i][j] += sum[i-1][j];
                    xcnt[i][j] += xcnt[i-1][j];
                }
                if(j > 0){
                    sum[i][j] += sum[i][j-1];
                    xcnt[i][j] += xcnt[i][j-1];
                }
                if(i > 0 && j > 0){
                    sum[i][j] -= sum[i-1][j-1];
                    xcnt[i][j] -= xcnt[i-1][j-1];
                }

                // ✅ both conditions
                if(sum[i][j] == 0 && xcnt[i][j] > 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};