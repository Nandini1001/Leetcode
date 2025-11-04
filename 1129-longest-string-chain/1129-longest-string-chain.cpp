class Solution {
public:
    static bool comp(string& a, string& b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                dp[ind][prev+1]=dp[ind+1][prev+1];
                if(prev==-1 || oneextra(words[ind],words[prev]))
                    dp[ind][prev+1]=max(dp[ind][prev+1],1+dp[ind+1][ind+1]);
            }
        }
        return dp[0][-1+1];
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


//tabulation