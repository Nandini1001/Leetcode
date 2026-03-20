class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1,0));
        for(int i=0;i+k-1<n;i++){
            for(int j=0;j+k-1<m;j++){
                vector<int> elements;
                for(int ii=0;ii<k;ii++){
                    for(int jj=0;jj<k;jj++){
                        elements.push_back(grid[i+ii][j+jj]);
                    }
                }
                sort(elements.begin(), elements.end());
                int mini=1e9;
                for(int el=1; el<elements.size(); el++){
                    if(elements[el]==elements[el-1]) continue;
                    mini=min(mini, abs(elements[el]-elements[el-1]));
                }
                ans[i][j]=mini==1e9?0:mini;
            }
        }
        return ans;
    }
};