class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        /* dfs
        int V=graph.size();
        vector<int> color(V,-1);
	    // for connected components
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, graph) == false) 
	                return false; 
	        }
	    }
	    return true;*/
        int V=graph.size();
        queue<pair<int,int>>q;
        vector<int> color(V,-1); 
        for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
                q.push({i,0});
                color[i]=0;
	            if(bfs(q, color, graph) == false) 
	                return false; 
	        }
	    }
        return true;
    }
    bool bfs(queue<pair<int,int>> q, vector<int>& color, vector<vector<int>>& graph){
        while(!q.empty()){
            int node=q.front().first;
            int clr=q.front().second;
            q.pop();
            for(int neighbour:graph[node]){
                if(color[neighbour]==-1){
                    q.push({neighbour,!clr});
                    color[neighbour]=!clr;
                }
                else if(color[neighbour]==clr)
                    return false;
            }
        }
        return true;
    }
    /*bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col; 
        int v=graph.size();
        // traverse adjacent nodes
        for(int neighbor : graph[node]) {
            if(color[neighbor] == -1) {
            if(!dfs(neighbor, !col, color, graph))
                return false;
            }
            else if(color[neighbor] == col) {
                return false;
            }
        }
        return true; 
    }*/
    
};