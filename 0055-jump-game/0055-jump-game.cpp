class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=nums[0];
        for(int i=1;i<nums.size();i++){
            if(maxind<i) return false;
            maxind=max(maxind,i+nums[i]);
            if(maxind>=nums.size()-1) return true;
        }
        return maxind>=nums.size()-1;
    }
};