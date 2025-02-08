class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*TC=O(n*m)
        int n=matrix.size(),m=matrix[0].size(),k=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][m-1]>target)
            {
                k=i;
                break;
            }
            else
            {
                if(matrix[i][m-1]==target)
                    return true;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[k][i]==target)
                return true;
        }
        return 0;*/
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n*m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/m,col=mid%m;
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};