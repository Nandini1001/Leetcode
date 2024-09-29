class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=-1,b=-1;
        for(int i=0,j=nums.size()-1;i<=j;i++,j--)
        {
            if(nums[i]==target)
            {   
                if(a==-1) 
                    a=i;
                if(a!=-1)
                    i--;
            }  
            if(nums[j]==target)
            {
                if(b==-1)
                    b=j;
                if(b!=-1)
                    j++;
            }
            if(a!=-1 && b!=-1)
                break;
        }
        return{a,b};
    }
};