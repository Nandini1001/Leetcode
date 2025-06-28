class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size()-1;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        int ans1=prev;
        prev=nums[1];
        prev2=0;
        for(int i=2;i<nums.size();i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return max(ans1,prev);
    }
};