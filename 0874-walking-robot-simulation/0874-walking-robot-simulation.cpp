class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, ans = 0;
        unordered_map<string, int> obsmap;
        for(auto i: obstacles){
            string obs=to_string(i[0])+"_"+to_string(i[1]);
            obsmap[obs]=1;
        }
        pair<int, int> dir={0,1};
        for(auto i: commands){
            if(i==-1){
                dir={dir.second, -dir.first};
            }
            else if(i==-2){
                dir={-dir.second, dir.first};
            }
            else{
                for(int j=0; j<i; j++){
                    int newx=x+dir.first;
                    int newy=y+dir.second;
                    if(obsmap.count(to_string(newx)+"_"+to_string(newy))){
                        break;
                    }
                    x=newx;
                    y=newy;
                }
            }
            ans=max(ans, (x*x)+(y*y));
        }
        return ans;
    }
};