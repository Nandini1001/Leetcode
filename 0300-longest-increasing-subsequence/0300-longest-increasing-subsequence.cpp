class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxlen=0;
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
};


//method use to print LIS
//prev is direct tabulation