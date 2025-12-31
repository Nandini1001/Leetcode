class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size(), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canCross(row, col, cells, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Flood cells
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        // Start BFS from top row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == row - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    !vis[nr][nc] && grid[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
};
