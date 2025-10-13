class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1;i<words.size();i++){
            if(isanagram(words[i-1],words[i])){
                words.erase(words.begin()+i);
                i--;}
        }
        return words;
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