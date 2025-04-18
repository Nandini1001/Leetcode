class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> ans;
        vector<int> indegree(v);
        vector<vector<int>> adj(v);
        int i=0;
        for(auto it:graph){
            indegree[i]=it.size();
            for(auto j:it){
                adj[j].push_back(i);
            }
            i++;
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};