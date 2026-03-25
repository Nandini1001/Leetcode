class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        if(sum%2) return false;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }
        if(sum%2) return false;
        long long horizontal=sum;
        //horizontal
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                horizontal-=grid[i][j];
            }
            if(horizontal==sum/2) return true;
        }
        long long vertical=sum;
        //vertical
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vertical-=grid[j][i];
            }
            if(vertical==sum/2) return true;
        }
        return false;
    }
};