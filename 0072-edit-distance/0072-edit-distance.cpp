class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=word1.size(), w2=word2.size();
        vector<vector<int>> dp(w1, vector<int>(w2,-1));
        return helper(word1, word2, w1-1, w2-1, dp);
    }
    int helper(string word1, string word2, int i1, int i2, vector<vector<int>>& dp){
        if(i1<0 ) return i2+1;
        if(i2<0 ) return i1+1;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(word1[i1]==word2[i2]) return dp[i1][i2]=helper(word1, word2, i1-1, i2-1, dp);
        return dp[i1][i2]=1+min({helper(word1, word2, i1-1, i2, dp), helper(word1, word2, i1, i2-1, dp), helper(word1, word2, i1-1, i2-1, dp)});
    }
};