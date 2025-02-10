class Solution {
private:
    int maximum(vector<vector<int>>& mat, int col)
    {
        int row=-1,maxel=INT_MIN,n=mat.size();
        for(int i=0;i<n;i++)
        {   if(maxel<mat[i][col])
            {
                maxel=mat[i][col];
                row=i;
            }
        }
        return row;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),row;
        int low=0,high=m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            row=maximum(mat,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right )
                return {row,mid};
            if(mat[row][mid]<right)
                low=mid+1;
            else 
                high=mid-1;
        }
        return{-1,-1};
    }
};