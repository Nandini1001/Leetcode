class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prevsum;
        prevsum[0]=1;
        int sum=0, cnt=0;
        for(auto i:nums){
            sum+=i;
            int req=sum-goal;
            cnt+=prevsum[req];
            prevsum[sum]++;
        }
        return cnt;
    }
};