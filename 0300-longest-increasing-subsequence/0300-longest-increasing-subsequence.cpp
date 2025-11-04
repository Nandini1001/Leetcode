class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                dp[ind][prev+1]=dp[ind+1][prev+1];
                if(prev==-1 || nums[ind]>nums[prev])
                    dp[ind][prev+1]=max(dp[ind][prev+1],1+dp[ind+1][ind+1]);
            }
        }
        return dp[0][-1+1];
    }
};


//tabulation
//prev is memoization written recursion

