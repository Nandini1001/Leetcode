class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector<int> prev(m+1,0), cur(m+1,0);
        for(int i=0;i<=m;i++) prev[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        if(prev[m]!=-1) return prev[m];
        return 0;
    }
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*longestCommonSubsequence(word1,word2);
    }
};