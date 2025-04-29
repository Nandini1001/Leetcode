/*class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> ways(n,0);
        vector<long long> dist(n,LLONG_MAX);
        int mod=(int)(1e9+7);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(it.second+1LL*time<dist[it.first]){
                    dist[it.first]=it.second+time;
                    ways[it.first]=ways[node];
                    pq.push({dist[it.first],it.first});
                }
                else if(it.second+time==dist[it.first])
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};*/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> ways(n,0);
        vector<long long> dist(n,LLONG_MAX);
        int mod=(int)(1e9+7);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long newTime = time + 1LL * it.second;
                if(newTime < dist[it.first]){
                    dist[it.first]=newTime;
                    ways[it.first]=ways[node];
                    pq.push({dist[it.first],it.first});
                }
                else if(newTime == dist[it.first]){
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
