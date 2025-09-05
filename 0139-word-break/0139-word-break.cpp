class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        if(solve(0,s,wordDict,dp)) return true;
        return false;
    }
    int solve(int start, string& s, vector<string>& wordDict,vector<int>& dp){
        if(start==s.size()) return 1;
        if(dp[start]!=-1) return dp[start];
        for(int i=start;i<s.size();i++){
            if(find(wordDict.begin(), wordDict.end(),s.substr(start,i-start+1))!=
            wordDict.end()){
                if(solve(i+1,s,wordDict,dp)) return dp[start]=1;
            }
        }
        return dp[start]=0;
    }
};