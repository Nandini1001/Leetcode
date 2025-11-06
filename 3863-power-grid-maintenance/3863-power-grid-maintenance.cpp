#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Merge all given connections
        for (auto &it : connections) {
            dsu.unite(it[0], it[1]);
        }

        // Create a map: component -> set of nodes
        unordered_map<int, set<int>> comp;
        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            comp[root].insert(i);
        }

        vector<int> ans;
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);

            if (type == 2) {
                // remove node x from its component
                comp[root].erase(x);
            } else {
                // find smallest available node in same component
                if (comp[root].find(x) != comp[root].end())
                    ans.push_back(x);
                else
                    ans.push_back(comp[root].empty() ? -1 : *comp[root].begin());
            }
        }
        return ans;
    }
};
