class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    if(!isvalid(board,i,j)) return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>& board, int row, int col){
        char c=board[row][col];
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==c) return false;
            if(i!=row && board[i][col]==c) return false;
            int newrow=3*(row/3)+i/3, newcol=3*(col/3)+i%3;
            if(newrow!=row && newcol!=col && board[newrow][newcol]==c) return false;
        }
        return true;
    }
};