class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int ind=0;
        int prev=-1, len=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                len=i-ind;
                if(len>=2*k) return true;
                if(prev>=k && len>=k) return true;
                prev=len;
                ind=i;
            }
        }
        int i=nums.size();
        len=i-ind;
        if(len>=2*k) return true;
        if(prev>=k && len>=k) return true;
        return false;
    }
};

//this is clean version of optimal


//1ans brute force
//2 and 3 wrong of optimal
