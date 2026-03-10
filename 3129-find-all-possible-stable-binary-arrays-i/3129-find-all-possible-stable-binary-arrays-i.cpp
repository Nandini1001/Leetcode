class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(zero+1,vector<vector<long long>>(one+1,vector<long long>(2,0)));
        dp[0][0][0]=1;
        dp[0][0][1]=1;
        for(int zeroo=0;zeroo<=zero;zeroo++){
            for(int onee=0;onee<=one;onee++){
                if(!zeroo && !onee) continue;
                long long cnt=0;
                for(int z=1;z<=min(limit, zeroo);z++){
                    cnt=(cnt+dp[zeroo-z][onee][0])%MOD;
                }
                dp[zeroo][onee][1]= cnt;
                cnt=0;
                for(int o=1;o<=min(limit, onee);o++){
                    cnt=(cnt+dp[zeroo][onee-o][1])%MOD;
                }
                dp[zeroo][onee][0]= cnt;
            }
        }
        int zerostart=dp[zero][one][1];
        int onestart=dp[zero][one][0];
        return (zerostart+onestart)%MOD;
    }
};