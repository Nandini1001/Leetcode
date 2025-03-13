class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";
        stack<int> st;
        string ans;
        for(int i:num)
        {
            while(ans.size() && k>0 && ans.back()>i)
            {
                ans.pop_back();
                k--;
            }
            ans+=i;
        }
        while(ans.size() && k>0)
        {
            ans.pop_back();
            k--;
        }
        /*while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }*/
        while(ans.size() && ans.front()=='0')
            ans.erase(ans.begin());
        if(!ans.size()) return "0";
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};