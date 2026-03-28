class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> nge;
        int i=nums2.size()-1;
        while(i>=0){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()) nge[nums2[i]]=-1;
            else nge[nums2[i]]=st.top();
            st.push(nums2[i]);
            i--;
        }
        for(auto ii:nums1){
            ans.push_back(nge[ii]);
        }
        return ans;
    }
};