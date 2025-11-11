class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();

        vector<int>adj[v];
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
                //bfs(i,isConnected,vis);
            }
        }
        return cnt;
    }
    void bfs(int start, vector<int> adjls[], vector<int>& vis){
    //void bfs(int start, vector<vector<int>>& adjls, vector<int>& vis){    
        queue<int> q;
        //int v=adjls.size();
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i:adjls[curr])
            //for(int i=0;i<v;i++)
            {
                if(!vis[i]){
                //if(adjls[curr][i] && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
};


//32 line added