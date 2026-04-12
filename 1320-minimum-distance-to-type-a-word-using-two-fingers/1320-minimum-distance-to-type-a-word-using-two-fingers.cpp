class Solution {
public:
    int minimumDistance(string word) {
        int n=word.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(27, vector<int>(27,-1)));
        return helper(word, 0, -1, -1, dp);
    }
    int helper(string& word, int ind, int fin1, int fin2, vector<vector<vector<int>>>& dp){
        if(ind==word.size()) return 0;
        if(dp[ind][fin1+1][fin2+1]!=-1) return dp[ind][fin1+1][fin2+1];
        int pos_no=word[ind]-'A';
        int i=pos_no/6;
        int j=pos_no%6;
        int finger1cost, finger2cost;
        if(fin1==-1) finger1cost=0;
        else{
            int f1x=fin1/6;
            int f1y=fin1%6;
            finger1cost=abs(i-f1x) + abs(j-f1y);
        }
        int finger1=finger1cost+ helper(word, ind+1, pos_no, fin2, dp);
        if(fin2==-1) finger2cost=0;
        else{
            int f2x=fin2/6;
            int f2y=fin2%6;
            finger2cost=abs(i-f2x) + abs(j-f2y);
        }
        int finger2=finger2cost+ helper(word, ind+1, fin1, pos_no, dp);
        return dp[ind][fin1+1][fin2+1]=min(finger1, finger2);
    }
};