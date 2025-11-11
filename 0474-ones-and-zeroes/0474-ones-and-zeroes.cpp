class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(101,vector<int>(101,-1)));
        return helper(strs.size()-1,0,0,m,n,strs,dp);
    }
    int helper(int ind, int zero, int one, int m, int n, vector<string>& strs, 
    vector<vector<vector<int>>>& dp){
        if(ind<0) return 0;
        if(dp[ind][zero][one]!=-1) return dp[ind][zero][one];
        int z=0, o=0;
        for(char i:strs[ind]){
            if(i=='0') z++;
            else o++;
        }
        int take=0;
        if(zero+z<=m && one+o<=n){
            take=1+helper(ind-1,zero+z,one+o,m,n,strs,dp);
        }
        int nottake=helper(ind-1,zero,one,m,n,strs,dp);
        return dp[ind][zero][one]=max(take,nottake);
    }
};


//memoization