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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mapmailnode;
        int n=accounts.size();
        disjoint ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end())
                    mapmailnode[mail]=i;
                else
                    ds.disjointbyrank(i,mapmailnode[mail]);
            }
        }
        vector<string> mergemail[n];
        for(auto it:mapmailnode){
            string mail=it.first;
            int node=ds.parentu(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergemail[i].size()==0) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergemail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};