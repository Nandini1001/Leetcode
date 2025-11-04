class Solution {
public:
    static bool comp(string& a, string& b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return helper(0,-1,words,dp);
    }
    int helper(int ind, int prev, vector<string>& words, vector<vector<int>>& dp){
        if(ind==words.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int maxlen=helper(ind+1,prev,words,dp);
        if(prev==-1 || oneextra(words[ind],words[prev])){
            maxlen=max(maxlen,1+helper(ind+1,ind,words,dp));
        }
        return dp[ind][prev+1]=maxlen;
    }
    bool oneextra(string& a, string& b){
        if(a.size()!=b.size()+1) return false;
        int first=0, second=0;
        while(first<a.size()){
            if(second<b.size() && a[first]==b[second]){
                first++;
                second++;
            }
            else first++;
        }
        if(first==a.size() && second==b.size()) return true;
        return false;
    }
};


//memoization