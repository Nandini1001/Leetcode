class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V);
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    // for connected components
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, graph) == false) 
	                return false; 
	        }
	    }
	    return true; 
    }
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
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
    }
};