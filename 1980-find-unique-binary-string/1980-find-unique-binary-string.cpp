class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        unordered_set<string> st;
        for(string i:nums)
            st.insert(i);
        for(int i=0;i<(1<<n);i++){
            string s;
            for(int j=0;j<n;j++){
                if(i & (1<<j)) s+='1';
                else s+='0';
            }
            if(st.find(s)==st.end()) return s;
        }
        return "";
    }
};