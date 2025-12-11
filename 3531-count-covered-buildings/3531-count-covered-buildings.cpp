class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,set<int>> vertical;
        unordered_map<int, set<int>> horizontal;
        for(int i=0; i<buildings.size();i++){
            vertical[buildings[i][0]].insert(buildings[i][1]);
            horizontal[buildings[i][1]].insert(buildings[i][0]);
        }
        int cnt=0;
        for(auto it: buildings){
            int x=it[0];
            int y=it[1];
            if((vertical.find(x)!=vertical.end() && *vertical[x].begin()<y && *vertical[x].rbegin()>y) && 
            (horizontal.find(y)!=horizontal.end() && *horizontal[y].begin()<x && *horizontal[y].rbegin()>x))
                cnt++;
        }
        return cnt;
    }
};