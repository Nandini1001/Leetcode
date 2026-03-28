class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=-1;
        stack<int> st;
        for(int i=0;i<heights.size(); i++){
            if(st.empty() || heights[st.top()]<=heights[i])
                st.push(i);
            else{
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int curind=st.top();
                    st.pop();
                    int nsi=i;
                    int psi=st.empty()?-1:st.top();
                    maxarea=max(maxarea, heights[curind]*(nsi-psi-1));
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int curind=st.top();
            st.pop();
            int nsi=heights.size();
            int psi=st.empty()?-1:st.top();
            maxarea=max(maxarea, heights[curind]*(nsi-psi-1));
        }
        return maxarea;
    }
};