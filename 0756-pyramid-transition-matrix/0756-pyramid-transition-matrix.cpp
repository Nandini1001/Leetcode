class Solution {
public:

    unordered_map<string,bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> mpp;
        for(string s:allowed){
            mpp[s.substr(0,2)].push_back(s[2]);
        }
        return helper(mpp,bottom, "", 1);
    }
    bool helper(unordered_map<string,vector<char>> &mpp, string& bottom, string top, int ind){
        if(ind==bottom.size() && top.size()==1) return true;
        if(ind==bottom.size()){
            if(helper(mpp,top,"",1)) return true;
        }
        string key=bottom+to_string(ind)+top;
        if(memo.count(key)) return memo[key];
        if(mpp.find(bottom.substr(ind-1,2))==mpp.end()) return memo[key]=false;
        vector<char> mapped=mpp[bottom.substr(ind-1,2)];
        for(int i=0;i<mapped.size();i++){
            top.push_back(mapped[i]);
            if(helper(mpp,bottom,top,ind+1)) return memo[key]=true;
            top.pop_back();
        }
        return memo[key]=false;
    }
};