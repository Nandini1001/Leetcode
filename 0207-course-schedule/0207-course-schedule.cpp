class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int course=q.front();
            cnt++;
            q.pop();
            for(auto it:adj[course])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return cnt==numCourses;
    }
};