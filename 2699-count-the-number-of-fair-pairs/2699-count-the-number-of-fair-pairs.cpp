class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            int low=lower-nums[i];
            int high=upper-nums[i];
            auto l=lower_bound(nums.begin()+i+1,nums.end(),low);
            auto r=upper_bound(nums.begin()+i+1,nums.end(),high);
            cnt+=(r-l);
        }
        return cnt;
    }
};