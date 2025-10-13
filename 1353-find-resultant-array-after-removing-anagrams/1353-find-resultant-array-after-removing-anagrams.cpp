class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int prev=0;
        for(int i=1;i<words.size();i++){
            if(!isanagram(words[prev],words[i])){
                ans.push_back(words[prev]);
                prev=i;
            }
        }
        ans.push_back(words[prev]);
        return ans;
    }
    bool isanagram(string s1, string s2){
        multiset<char> st;
        for(auto i:s1) st.insert(i);
        for(auto i:s2){
            if(st.find(i)!=st.end()) st.erase(st.find(i));
            else return false;
        }
        return st.empty();
    }
};