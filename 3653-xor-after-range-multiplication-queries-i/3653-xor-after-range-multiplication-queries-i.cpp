class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        for(auto i: queries){
            int l=i[0], r=i[1], k=i[2], v=i[3];
            while(l<=r){
                nums[l]=(1LL*nums[l]*v)%mod;
                l+=k;
            }
        }
        int xorr=0;
        for(int i:nums) xorr^=i;
        return xorr;
    }
};