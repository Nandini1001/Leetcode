class Solution {
private:
    int maxrect(vector<int>& nums)
    {
        int maxArea=0;
        stack<int> st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                int element=nums[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,element*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int nse=nums.size();
            int element=nums[st.top()];
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,element*(nse-pse-1));
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<vector<int>> presum(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=(matrix[j][i]-'0');
                if(matrix[j][i]=='0') sum=0;
                presum[j][i]=sum;
            }
        }
        for(int i=0;i<n;i++)
        {
            maxArea=max(maxArea,maxrect(presum[i]));
        }
        return maxArea;
    }
};