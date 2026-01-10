class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
       return helper (0,0,s1,s2,dp);
    }
    int helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i==s1.size()||j==s2.size())
        {
            int sum=0;
            for(;i<s1.size();i++){
                sum+=(int)s1[i];
            }
            for(;j<s2.size();j++){
                sum+=(int)s2[j];
            }
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int takeij=INT_MAX;
        if(s1[i]==s2[j])
            takeij=helper(i+1,j+1,s1,s2,dp);
        int takej=(int)s1[i]+helper(i+1,j,s1,s2,dp);
        int takei=(int)s2[j]+helper(i,j+1,s1,s2,dp);
        return dp[i][j]=min(takeij,min(takei,takej));
    }
};