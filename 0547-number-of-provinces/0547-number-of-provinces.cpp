class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j)
                    adj[i].push_back(j);
            }
        }
        vector<int> vis(v,0);
        int cnt=0;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
    void bfs(int start, vector<vector<int>>& adjls, vector<int>& vis){
        queue<int> q;
        vis[start]=1;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(int i:adjls[curr])
            {
                if(!vis[i])
                    q.push(i);
            }
        }
    }
};