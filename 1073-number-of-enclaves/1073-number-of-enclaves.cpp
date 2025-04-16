class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>  q;
        for(int j=0;j<m;j++){
            if(grid[0][j])
            {
                vis[0][j]=1;
                q.push({0,j});
            }
            if(grid[n-1][j])
            {
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0])
            {
                vis[i][0]=1;
                q.push({i,0});
            }
            if(grid[i][m-1])
            {
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        bfs(q,vis,grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j])
                    cnt++;
            }
        }
        return cnt;
    }

    void bfs(queue<pair<int,int>>q, vector<vector<int>> &vis, vector<vector<int>>& board){
        int drow[]={0,0,-1,+1};
        int dcol[]={-1,+1,0,0};
        int n=board.size();
        int m=board[0].size();
        while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        //board[r][c]=0;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol])
            {
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
        }
    }
};