class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> front(n+1,0), back(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                back[prev+1]=front[prev+1];
                if(prev==-1 || nums[ind]>nums[prev])
                    back[prev+1]=max(back[prev+1],1+front[ind+1]);
            }
            front=back;
        }
        return front[-1+1];
    }
};


//space optimisation