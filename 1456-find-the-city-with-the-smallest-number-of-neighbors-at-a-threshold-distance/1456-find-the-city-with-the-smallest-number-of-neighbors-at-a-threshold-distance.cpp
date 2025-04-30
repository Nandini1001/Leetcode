class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,1e9));
        for(auto it: edges){
            cost[it[0]][it[1]]=it[2];
            cost[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) cost[i][j]=0;
            }
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                }
            }
        }
        int ans=INT_MIN;
        int anscnt=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(anscnt>cnt) {
                ans=i;
                anscnt=cnt;
            }
            else if(anscnt==cnt) ans=max(ans,i);
        }
        return ans;
    }
};