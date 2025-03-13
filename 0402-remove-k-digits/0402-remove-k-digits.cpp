class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";
        stack<int> st;
        string ans;
        for(int i:num)
        {
            while(!st.empty() && k>0 && st.top()>i)
            {
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        while(ans.size() && ans.back()=='0')
            ans.pop_back();
        if(!ans.size()) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};