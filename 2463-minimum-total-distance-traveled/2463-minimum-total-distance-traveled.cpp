class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factorypos;
        for(int i=0; i<factory.size(); i++){
            int pos=factory[i][0];
            int limit=factory[i][1];
            for(int j=0; j<limit; j++){
                factorypos.push_back(pos);
            }
        }
        vector<vector<long long>> dp(robot.size(),vector<long long>(factorypos.size(),-1));
        return helper(0, 0, robot, factorypos,dp);
    }
    long long helper(int ri, int fi, vector<int>& robot, vector<int>& factorypos, vector<vector<long long>>& dp){
        if(ri>=robot.size()) return 0;
        if(fi>=factorypos.size()) return 1e18;
        if(dp[ri][fi]!=-1) return dp[ri][fi];
        long long take=abs(factorypos[fi]-robot[ri])+helper(ri+1, fi+1, robot, factorypos,dp);
        long long skip=helper(ri, fi+1, robot, factorypos, dp);
        return dp[ri][fi]=min(take, skip);
    }
};