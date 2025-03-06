class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size();
        int xor1=0, xor2=0;
        map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                mpp[grid[i][j]]++;
                if(mpp[grid[i][j]]==2)
                {
                    ans.push_back(grid[i][j]);
                }
                else xor2^=grid[i][j];
            }
        }
        for(int i=1;i<=n*n;i++)
            xor1^=i;
        ans.push_back(xor1^xor2);
        return ans;
    }
};