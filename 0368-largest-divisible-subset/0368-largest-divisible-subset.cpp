class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxlen=0, lastind=0;
        vector<int> dp(nums.size(),1);
        vector<int> ind(nums.size());
        for(int i=0;i<nums.size();i++){
            ind[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                    ind[i]=prev;
                }
            }
            if(maxlen<dp[i]){
                maxlen=dp[i];
                lastind=i;
            }
        }
        vector<int> ans;
        while(ind[lastind]!=lastind){
            ans.push_back(nums[lastind]);
            lastind=ind[lastind];
        }
        ans.push_back(nums[lastind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


