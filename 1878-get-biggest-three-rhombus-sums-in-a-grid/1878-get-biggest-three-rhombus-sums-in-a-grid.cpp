class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> left(n,vector<int>(m,0));
        vector<vector<int>> right(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                left[i][j]=grid[i][j];
                if(i+1<n && j-1>=0) left[i][j]+=left[i+1][j-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                right[i][j]=grid[i][j];
                if(i+1<n && j+1<m) right[i][j]+=right[i+1][j+1];
            }
        }
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int minmove=min({j,m-1-j,(n-1-i)/2});
                for(int move=0;move<=minmove;move++){
                    int sum=0;
                    if(!move) sum=grid[i][j];
                    else{
                        int topleft=left[i][j]-left[i+move][j-move];
                        int toprt=right[i][j]-right[i+move][j+move];
                        int bottomrt=left[i+move][j+move]-left[i+(2*move)][j]+grid[i+(2*move)][j];
                        int bottomleft=right[i+move][j-move]-right[i+(2*move)][j];
                        sum=topleft+toprt+bottomleft+bottomrt-grid[i][j];
                    }
                    st.insert(sum);
                    if(st.size()>3) st.erase(st.begin());
                }
            }
        }
        vector<int> ans(st.rbegin(), st.rend());
        return ans;
    }
};