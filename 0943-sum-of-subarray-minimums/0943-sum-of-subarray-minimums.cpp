class Solution {
private:
    vector<int> nse(vector<int>& nums)
    {
        vector<int> nsee(nums.size());
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            nsee[i]=st.empty()?nums.size():st.top();
            st.push(i);
        }
        return nsee;
    }
    vector<int> pse(vector<int>& nums)
    {
        vector<int> psee(nums.size());
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
                st.pop();
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nsee=nse(arr);
        vector<int> psee=pse(arr);
        int ans=0;
        int mod=int(1e9+7);
        for(int i=0;i<arr.size();i++)
        {
            int left=i-psee[i];
            int right=nsee[i]-i;
            ans=(ans+(left*right*(1l)*arr[i])%mod)%mod;
        }
        return ans;
    }
};