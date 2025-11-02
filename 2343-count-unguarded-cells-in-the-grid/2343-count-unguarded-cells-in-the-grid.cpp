class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mark(m,vector<int>(n,-1));
        for(int i=0;i<guards.size();i++){
            mark[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++){
            mark[walls[i][0]][walls[i][1]]=0;
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<guards.size();i++){
            int newr=guards[i][0];
            int newc=guards[i][1];
            for(int j=0;j<4;j++){
                int newr=guards[i][0]+dr[j];
                int newc=guards[i][1]+dc[j];
                while(newr >= 0 && newr < m && newc >= 0 && newc < n && 
                    mark[newr][newc] != 0 && mark[newr][newc] != 1){
                    mark[newr][newc]=2;
                    /*if(j==0) newr--;
                    else if(j==1) newr++;
                    else if(j==2) newc--;
                    else newc++;*/
                    newr+=dr[j];
                    newc+=dc[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mark[i][j] == -1) ans++;
            }
        }
        return ans;
    }
};


//TC: O(n*m)
//optimisation but not in time complexity only in code