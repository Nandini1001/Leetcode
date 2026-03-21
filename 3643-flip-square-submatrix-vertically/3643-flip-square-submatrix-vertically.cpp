class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int xx=0;xx<k/2;xx++){
            for(int yy=y;yy<y+k;yy++){
                swap(grid[x+xx][yy], grid[x+k-1-xx][yy]);
            }
        }
        return grid;
    }
};