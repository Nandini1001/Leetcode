class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cntone=0;
        for(auto it:nums){
            if(it==1) cntone++;
        }
        if(cntone>0) return nums.size()-cntone;
        int minlen=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int g=nums[i];
            for(int j=i+1;j<nums.size();j++){
                g=gcd(nums[j],g);
                if(g==1){
                    minlen=min(minlen,j-i+1);
                    break;
                }
            }
        }
        if(minlen!=INT_MAX) return minlen-1+nums.size()-1;
        return -1;
    }
};