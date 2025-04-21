/*class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        q.push({0,{0,0}});
        vector<vector<int>>dis (n,vector<int>(n,1e9));
        dis[0][0]=0;
        int drow[]={0,0,-1,+1,+1,+1,-1,-1};
        int dcol[]={-1,+1,0,0,+1,-1,+1,-1};
        while(!q.empty()){
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !grid[nr][nc] && 1+dist<dis[nr][nc]){
                    dis[nr][nc]=1+dist;
                    if(nr==n-1 && nc==n-1) return dist+1;
                    q.push({1+dist,{nr,nc}});
                }
            }
        }
        return -1;
    }
};*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 1;

        int drow[] = {0, 0, -1, +1, +1, +1, -1, -1};
        int dcol[] = {-1, +1, 0, 0, +1, -1, +1, -1};

        while (!q.empty()) {
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if (r == n - 1 && c == n - 1) return dist;

            for (int i = 0; i < 8; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !grid[nr][nc] && dist + 1 < dis[nr][nc]) {
                    dis[nr][nc] = dist + 1;
                    q.push({dist + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
