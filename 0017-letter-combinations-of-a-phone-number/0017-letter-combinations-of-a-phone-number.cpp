class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s;
        solve(0,digits,ans,s,mapping);
        return ans;
    }
    void solve(int ind, string digits, vector<string>& ans, string s, vector<string> mapping){
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }
        char mapind=digits[ind];
        string alpha=mapping[mapind-'0'];
        for(int i=0;i<alpha.size();i++){
            s+=alpha[i];
            solve(ind+1,digits,ans,s,mapping);
            s.pop_back();
        }
    }
};