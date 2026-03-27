class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{' ||  c=='[') st.push(c);
            else{
                if(st.empty()) return false;
                char cc=st.top();
                st.pop();
                if((c==')' && cc=='(') || (c==']' && cc=='[') || (c=='}' && cc=='{')){
                    continue;
                }
                else return false;
            }
        }
        return st.empty();
    }
};