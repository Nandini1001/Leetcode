class Solution {
private:
    int first(vector<int>& nums, int target){
        int n=nums.size();
        int low=0, high=n-1, first=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return first;
    }
    int last(vector<int>& nums, int target){
        int n=nums.size();
        int low=0, high=n-1, last=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstt=first(nums,target);
        if(firstt==-1) return {-1,-1};
        int lastt=last(nums,target);
        return {firstt,lastt};
        /*int a=-1,b=-1;
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
        return{a,b};*/
    }
};