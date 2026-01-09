class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1e9));
        return helper(0,0,nums1,nums2,dp);
    }
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, 
    vector<vector<int>>& dp){
        if(i==nums1.size() || j==nums2.size()) return -1e8;
        if(dp[i][j]!=-1e9) return dp[i][j];
        int ans=nums1[i]*nums2[j];
        //if(helper(i+1, j+1, nums1, nums2,dp)!=INT_MIN)
        ans=max(ans,nums1[i]*nums2[j]+helper(i+1, j+1, nums1, nums2,dp));
        ans=max(ans,helper(i, j+1, nums1, nums2,dp));
        ans=max(ans,helper(i+1, j, nums1, nums2,dp));
        return dp[i][j]=ans;
    }
};


//my code