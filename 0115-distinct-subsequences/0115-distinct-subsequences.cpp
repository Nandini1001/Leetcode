class Solution {
public:
    int numDistinct(string s, string t) {
        int ss=s.size();
        int ts=t.size();
        vector<vector<int>> dp(ss, vector<int>(ts,-1));
        return helper(s, t, ss-1, ts-1, dp);
    }
    int helper(string& s, string& t, int si, int ti, vector<vector<int>>& dp){
        if(ti<0) return 1;
        if(si<0) return 0;
        if(dp[si][ti]!=-1) return dp[si][ti];
        if(s[si]==t[ti])
            return dp[si][ti]=helper(s, t, si-1, ti-1, dp) + helper(s, t, si-1, ti, dp);
        return dp[si][ti]=helper(s, t, si-1, ti,dp);
    }
};