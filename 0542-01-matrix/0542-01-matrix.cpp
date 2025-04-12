class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> matrix(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else
                    vis[i][j]=0;
            }
        }
        int drow[]={0,0,-1,+1};
        int dcol[]={-1,+1,0,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            matrix[row][col]=step;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
        return matrix;
    }
};