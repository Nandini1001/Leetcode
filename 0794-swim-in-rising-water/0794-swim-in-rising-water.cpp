class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        q.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        while(!q.empty()){
            int row=q.top().second.first;
            int col=q.top().second.second;
            int time=q.top().first;
            q.pop();
            if(row==n-1 && col==n-1) return time;
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr<n && newr>=0 && newc<n && newc>=0 && !vis[newr][newc]){
                    q.push({max(time,grid[newr][newc]),{newr,newc}});
                    vis[newr][newc]=1;
                }
            }
        }
        return 0;
    }
};