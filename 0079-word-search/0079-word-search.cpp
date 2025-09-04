class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(solve(1,i,j,word,board,vis))
                        return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
    bool solve(int ind, int row, int col, string word,
     vector<vector<char>>& board, vector<vector<int>>& vis){
        if(ind==word.size()) return true;
        int drow[]={0,-1,0,+1};
        int dcol[]={-1,0,+1,0};
        for(int i=0;i<4;i++){
            int newr=row+drow[i];
            int newc=col+dcol[i];
            if(newr>=0 && newr<board.size() && newc>=0 && newc<board[0].size() 
            && !vis[newr][newc] && board[newr][newc]==word[ind]){
                vis[newr][newc]=1;
                if(solve(ind+1,newr,newc,word,board,vis)) return true;
                vis[newr][newc]=0;
            }
        }
        return false;
     }
};