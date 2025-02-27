class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        fun(0,s,path,res);
        return res;
    }
    void fun(int ind, string s, vector<string>& path, vector<vector<string>>& res)
    {
        if(ind==s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(ispalindrome(s,ind,i))
            {
                path.push_back(s.substr(ind,i-ind+1));
                fun(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int start, int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};