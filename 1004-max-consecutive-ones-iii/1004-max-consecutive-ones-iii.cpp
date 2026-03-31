class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=0;
        int l=0, r=0, cnt0=0;
        while(r<nums.size()){
            if(nums[r]==0) cnt0++;
            if(cnt0>k){
                if(nums[l]==0) cnt0--;
                l++;
            }
            if(cnt0<=k) len=max(len, r-l+1);
            r++;
        }
        return len;
    }
};