class Solution {
public:
    void longestCommonSubsequence(string text1, string text2, int n, int m, vector<vector<int>> &dp) {
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        longestCommonSubsequence(str1,str2,n,m,dp);
        string ans="";
        int i=n, j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};