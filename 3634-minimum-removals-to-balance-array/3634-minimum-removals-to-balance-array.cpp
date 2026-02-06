class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minans=1e9;
        int n=nums.size();
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(j<n && nums[j]<=1LL*nums[i]*k)
                j++;
            minans=min(minans,n-(j-i));
        }
        return minans;
    }
};