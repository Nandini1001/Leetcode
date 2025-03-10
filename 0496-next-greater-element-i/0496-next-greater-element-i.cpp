class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        stack<int>st;
        int i=nums2.size()-1;
        while(i>=0)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            nge[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
            i--;
        }
        vector<int>ans;
        for(int n:nums1)
        {
            ans.push_back(nge[n]);
        }
        return ans;
    }
};