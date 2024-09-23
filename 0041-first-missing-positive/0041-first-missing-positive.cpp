class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int k=1;
        while(1)
        {
            if(mpp[k]==0)
            {
                return k;
            }
            k++;
        }
        /*for(auto it=hash.begin();it!=hash.end();it++)
        {
            if(hash[it]==0)
                return it;
        }*/
    }
};