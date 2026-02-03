class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int flag=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                if(flag==0 )
                    flag=1;
                else if(flag==2)
                    flag=3;
            }
            else if(nums[i]>nums[i+1]){
                if(flag==1 || flag==2)
                    flag=2;
                else return false;
            }
            else return false;
        }
        return (flag==3)?true:false;
    }
};