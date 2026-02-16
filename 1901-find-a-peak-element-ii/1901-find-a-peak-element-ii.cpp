class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0, high=mat[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxelrow=maxelement(mat,mid);
            int left=(mid-1)>=0?mat[maxelrow][mid-1]:-1;
            int right=(mid+1)<mat[0].size()?mat[maxelrow][mid+1]:-1;
            if(mat[maxelrow][mid]>left && mat[maxelrow][mid]>right)
                return {maxelrow,mid};
            if(mat[maxelrow][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {};
    }
    int maxelement(vector<vector<int>>& mat, int col){
        int ans=INT_MIN, ind=-1;
        for(int i=0;i<mat.size();i++){
            if(ans<mat[i][col]){
                ans=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
};