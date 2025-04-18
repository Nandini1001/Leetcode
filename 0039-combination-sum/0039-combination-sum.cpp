class Solution {
private:
    void findcombination(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(ind==candidates.size() || target==0 || target<0)
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        //if(candidates[ind]<=target)
        //{
            ds.push_back(candidates[ind]);
            findcombination(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        //}
        findcombination(ind+1,target,candidates,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0,target,candidates,ans,ds);
        return ans;
    }
};