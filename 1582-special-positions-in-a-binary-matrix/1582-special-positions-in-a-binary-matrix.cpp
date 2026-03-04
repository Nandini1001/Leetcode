class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row=0, n=mat.size(), m=mat[0].size();
        vector<int> rowcnt(n,0);
        vector<int> colcnt(m,0);
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    rowcnt[i]++;
                    colcnt[j]++;
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && rowcnt[i]==1 && colcnt[j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};