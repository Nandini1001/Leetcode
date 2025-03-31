class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;
        for(int i=0;i<nums.size();i++)
        {
            if(maxind<i) return false;
            if((i+nums[i])>maxind)
                maxind=i+nums[i];
        }
        return maxind>=nums.size()-1;
    }
};