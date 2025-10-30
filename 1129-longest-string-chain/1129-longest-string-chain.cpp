class Solution {
public:
    static bool comp(string& a, string& b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int maxlen=0;
        vector<int> dp(words.size(),1);
        for(int i=0;i<words.size();i++){
            for(int prev=0;prev<i;prev++){
                if(oneextra(words[i],words[prev]) && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
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


//method use to print LIS