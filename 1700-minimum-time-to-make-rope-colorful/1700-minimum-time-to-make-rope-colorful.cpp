class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0, maxtime=neededTime[0];
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                time+=min(maxtime,neededTime[i]);
                maxtime=max(maxtime,neededTime[i]);
            }
            else maxtime=neededTime[i];
        }
        return time;
    }
};