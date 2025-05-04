class disjoint {
public:
    vector<int> parent,rank;
    disjoint(int v){
        parent.resize(v);
        rank.resize(v,0);
        for(int i=0;i<v;i++)
            parent[i]=i;
    }
    int parentu(int node){
        if(node==parent[node])
            return node;
        return parent[node]=parentu(parent[node]);
    }
    void disjointbyrank(int u, int v){
        int upu=parentu(u);
        int upv=parentu(v);
        if(upu==upv) return;
        if(rank[upu]<rank[upv])
            parent[upu]=upv;
        else if(rank[upv]<rank[upu])
            parent[upv]=upu;
        else
        {
            parent[upu]=upv;
            rank[upv]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra=0;
        disjoint ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            int upu=ds.parentu(u);
            int upv=ds.parentu(v);
            if(upu==upv) extra++;
            else{
                ds.disjointbyrank(u,v);
            }
        }
        int cntc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntc++;
        }
        if(extra>=(cntc-1)) return cntc-1;
        return -1;
    }
};