class disjoint {
public:
    vector<int> parent, size;
    disjoint(int v){
        parent.resize(v+1);
        size.resize(v+1,1);
        for(int i=0;i<v;i++)
            parent[i]=i;
    }
    int parentu(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=parentu(parent[node]);
    }
    void unionbysize(int u, int v){
        int upu=parentu(u);
        int upv=parentu(v);
        if(upu==upv) return;
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        disjoint ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int ind=0;ind<4;ind++){
                    int dr=i+drow[ind];
                    int dc=j+dcol[ind];
                    if(dr>=0 && dr<n && dc>=0 && dc<n && grid[dr][dc]==1){
                        int nodeno=i*n+j;
                        int adjno=dr*n+dc;
                        ds.unionbysize(nodeno,adjno);
                    }
                }
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int dr=i+drow[ind];
                    int dc=j+dcol[ind];
                    if(dr>=0 && dr<n && dc>=0 && dc<n && grid[dr][dc]==1){
                        components.insert(ds.parentu(dr*n+dc));
                    }
                }
                int size=0;
                for(auto it:components){
                    size+=ds.size[it];
                mx=max(mx,size+1);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx, ds.size[ds.parentu(i)]);
        }
        return mx;
    }
};