class Solution {
private:
    int timer=1;
private:
    void dfs(int node, int parent, vector<int> edges[], int tin[], 
    int low[], vector<int>& vis, vector<vector<int>> & bridges ){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:edges[node]){
            if(it==parent) continue;
            if(vis[it]){
                low[node]=min(low[node],low[it]);
            }
            else{
                dfs(it,node,edges,tin,low,vis,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                    bridges.push_back({it,node});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        dfs(0,-1,adj,tin, low, vis, bridges);
        return bridges;
                
    }
};