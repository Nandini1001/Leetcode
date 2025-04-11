class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        vector<vector<int>> ans=image;
        int drow[]={-1,+1,0,0};
        int dcol[]={0,0,-1,+1};
        dfs(sr,sc,ans,image,drow,dcol,ini,color);
        return ans;
    }
    void dfs(int sr,int sc,vector<vector<int>>& ans, vector<vector<int>>& image, int drow[], int dcol[],int ini, int color)
    {
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==ini)
                dfs(nrow, ncol, ans, image, drow, dcol, ini, color);
        }
    }
};