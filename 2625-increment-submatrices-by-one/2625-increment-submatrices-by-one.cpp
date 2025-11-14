class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        for(auto it: queries ){
            int r1= it[0], c1=it[1], r2=it[2], c2=it[3];
            for(int r=r1;r<=r2;r++){
                ans[r][c1]+=1;
                if(c2+1<n)
                    ans[r][c2+1]-=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        return ans;
    }
};


//prev brute force this optimised using difference array technique
//TC= O(q*n  +   n*n)
//SC= O(n*n)  for ans