class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(1,k,n,ans,arr);
        return ans;
    }
    void solve(int start, int k, int sum, vector<vector<int>>& ans, vector<int> &arr){
        if(k==0 && sum==0) 
        {
            ans.push_back(arr);
            return;
        }
        for(int i=start;i<=9;i++){
            if(i>sum || (find(arr.begin(),arr.end(),i)!=arr.end())) continue;
            arr.push_back(i);
            solve(i+1,k-1,sum-i,ans,arr);
            arr.pop_back();
        }
    }
};