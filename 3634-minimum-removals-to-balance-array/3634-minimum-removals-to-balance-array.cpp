class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minans=1e9;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int ind=upper_bound(nums.begin()+i,nums.end(),1LL*nums[i]*k)-nums.begin();
            minans=min(minans,n-ind+i);
        }
        return minans;
    }
};