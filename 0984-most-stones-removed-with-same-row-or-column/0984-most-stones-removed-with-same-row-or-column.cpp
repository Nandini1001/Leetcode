class disjoint{
    vector<int> parent,rank;
public:
    disjoint(int v){
        parent.resize(v+1);
        rank.resize(v+1,0);
        for(int i=0;i<=v;i++)
            parent[i]=i;
    }
    int parentu(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=parentu(parent[node]);
    }
    void disjointbyrank(int u, int v){
        int upu=parentu(u);
        int upv=parentu(v);
        if(upv==upu) return;
        if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }
        else if(rank[upv]<rank[upu])
            parent[upv]=upu;
        else
        {
            parent[upv]=upu;
            rank[upu]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=-1,maxcol=-1;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        disjoint ds(maxrow+maxcol+1);
        unordered_map<int,int> mapnode;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxrow+1;
            ds.disjointbyrank(row,col);
            mapnode[row]=1;
            mapnode[col]=1;
        }
        int cnt=0;
        for(auto it:mapnode){
            if(ds.parentu(it.first)==it.first)
                cnt++;
        }
        return stones.size()-cnt;
    }
};