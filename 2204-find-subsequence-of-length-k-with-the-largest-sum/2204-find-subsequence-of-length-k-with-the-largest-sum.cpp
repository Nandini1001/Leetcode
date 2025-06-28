class Solution {
public:
    static bool comp(pair<int,int> val1, pair<int,int> val2){
        return val1.second>val2.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++)
            arr.push_back({i,nums[i]});
        sort(arr.begin(),arr.end(),comp);
        sort(arr.begin(),arr.begin()+k);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(arr[i].second);
        return ans;
    }
};