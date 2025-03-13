class Solution {
vector<int> pse(vector<int>& nums)
{
    vector<int> psee(nums.size());
    stack<int> st;
    for(int i=0;i<nums.size();i++)
    {
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        psee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return psee;
}
vector<int> nse(vector<int>& nums)
{
    vector<int> nsee(nums.size());
    stack<int> st;
    for(int i=nums.size()-1;i>=0;i--)
    {
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        nsee[i]=st.empty()?nums.size():st.top();
        st.push(i);
    }
    return nsee;
}
vector<int> pge(vector<int>& nums)
{
    vector<int> pgee(nums.size());
    stack<int> st;
    for(int i=0;i<nums.size();i++)
    {
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        pgee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pgee;
}
vector<int> nge(vector<int>& nums)
{
    vector<int> ngee(nums.size());
    stack<int> st;
    for(int i=nums.size()-1;i>=0;i--)
    {
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        ngee[i]=st.empty()?nums.size():st.top();
        st.push(i);
    }
    return ngee;
}
long long sum_subarray_min(vector<int>& nums)
{
    long long sum=0;
    vector<int> psee=pse(nums);
    vector<int> nsee=nse(nums);
    for(int i=0;i<nums.size();i++)
    {
        int left=i-psee[i];
        int right=nsee[i]-i;
        sum+=(left*right*(1l)*nums[i]);
    }
    return sum;
}
long long sum_subarray_max(vector<int>& nums)
{
    long long sum=0;
    vector<int> pgee=pge(nums);
    vector<int> ngee=nge(nums);
    for(int i=0;i<nums.size();i++)
    {
        int left=i-pgee[i];
        int right=ngee[i]-i;
        sum+=(left*right*(1l)*nums[i]);
    }
    return sum;
}
public:
    long long subArrayRanges(vector<int>& nums) {
        return sum_subarray_max(nums)-sum_subarray_min(nums);
    }
};