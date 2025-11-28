class Solution {
public:
    int count = 0;
    vector<vector<int>> adj;
    vector<int> values;
    int k;

    int dfs(int node, int parent) {
        long long sum = values[node] % k;

        for (int nxt : adj[node]) {
            if (nxt == parent) continue;
            int sub = dfs(nxt, node);

            if (sub == 0) {
                // Child subtree itself is divisible → this becomes one component
                count++;
            } else {
                sum = (sum + sub) % k;
            }
        }
        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        this->k = k;
        this->values = values;
        adj.assign(n, {});

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int rootSum = dfs(0, -1);

        // Root also forms a component if divisible
        if (rootSum % k == 0) count++;

        return count;
    }
};
