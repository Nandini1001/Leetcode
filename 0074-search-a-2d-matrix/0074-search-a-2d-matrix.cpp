class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
        return 0;
    }
};