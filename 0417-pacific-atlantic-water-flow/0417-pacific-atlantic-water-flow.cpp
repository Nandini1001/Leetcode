class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            pacific[0][i]=1;
            q.push({0,i});
        }
        for(int i=0;i<n;i++){
            pacific[i][0]=1;
            q.push({i,0});
        }
        bfs(dr,dc,heights,q,pacific);
        for(int i=0;i<m;i++){
            atlantic[n-1][i]=1;
            q.push({n-1,i});
        }
        for(int i=0;i<n;i++){
            atlantic[i][m-1]=1;
            q.push({i,m-1});
        }
        bfs(dr,dc,heights,q,atlantic);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
    void bfs(int dr[], int dc[], vector<vector<int>>& heights, queue<pair<int,int>>& q,
    vector<vector<int>>& mat){
        int n=heights.size();
        int m=heights[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==0 
                && heights[row][col]<=heights[nrow][ncol]){
                    mat[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
};