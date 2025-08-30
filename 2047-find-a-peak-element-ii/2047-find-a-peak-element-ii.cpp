class Solution {
public:
    int maxelement(int col, vector<vector<int>>& mat){
        int maxi=INT_MIN, n=mat.size(), maxind=-1;
        for(int row=0;row<n;row++)
            if(maxi<mat[row][col])
            {
                maxi=mat[row][col];
                maxind=row;
            }
        return maxind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size(), maxind;
        int low=0, high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            maxind=maxelement(mid,mat);
            int left=mid-1>=0?mat[maxind][mid-1]:-1;
            int right=mid+1<m?mat[maxind][mid+1]:-1;
            if(mat[maxind][mid]>left && mat[maxind][mid]>right)
            {    return {maxind,mid};
            }
            if(mat[maxind][mid]<right) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};