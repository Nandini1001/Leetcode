class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=word1.size(), w2=word2.size();
        vector<vector<int>> dp(w1+1, vector<int>(w2+1,-1));
        for(int i=0; i<=w1; i++) dp[i][0]=i;
        for(int i=0; i<=w2; i++) dp[0][i]=i;
        for(int i1=1; i1<=w1; i1++){
            for(int i2=1; i2<=w2; i2++){
                if(word1[i1-1]==word2[i2-1]) dp[i1][i2]=dp[i1-1][i2-1];
                else dp[i1][i2]=1+min({dp[i1-1][i2], dp[i1][i2-1], dp[i1-1][i2-1]});
            }
        }
        return dp[w1][w2];
    }
    
};