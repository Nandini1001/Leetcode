class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j){
                if(nums[i]==nums[j])
                    return true;}
            }
        }
        return false;*/
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>1)
                return true;
        }
        return false;
    }
};