class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m,1));
        for(int i=1;i<n*m;i++){
            ans[i/m][i%m]=(1LL*ans[(i-1)/m][(i-1)%m]*grid[(i-1)/m][(i-1)%m])%12345;
        }
        long long suffix=1;
        for(int i=(n*m)-2;i>=0;i--){
            suffix = (suffix * grid[(i+1)/m][(i+1)%m]) % 12345;
            ans[i/m][i%m]=(ans[i/m][i%m]*suffix)%12345;
        }
        return ans;
    }
};