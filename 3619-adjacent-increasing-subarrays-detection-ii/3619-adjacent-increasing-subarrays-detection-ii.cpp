class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans=0;
        int len=0, prev=0, ind=0;
        int maxlen,minlen;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                len=i-ind;
                maxlen=max(len,prev)%2?max(len,prev)-1:max(len,prev);
                minlen=min(len,prev);
                if(maxlen/2>minlen) 
                    ans=max(ans,maxlen/2);
                else ans=max(ans,minlen);
                prev=len;
                ind=i;
            }
        }
        int i=nums.size();
        len=i-ind;
        maxlen=max(len,prev)%2?max(len,prev)-1:max(len,prev);
        minlen=min(len,prev);
        if(maxlen/2>minlen) 
            ans=max(ans,maxlen/2);
        else ans=max(ans,minlen);
        return ans;
    }
};