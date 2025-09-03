class Solution {
public: 
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(0,0,n,0,ans,s);
        return ans;
    }
    void solve(int open, int close, int n, int ind, vector<string>& ans, string s ){
        if(open>n) return;
        if(close>open) return;
        if(ind==2*n)
        {
            ans.push_back(s);
            return;
        }
        s+='(';
        solve(open+1,close,n,ind+1,ans,s);
        s.pop_back();
        s.push_back(')');
        solve(open, close+1,n,ind+1,ans,s);
    }
};