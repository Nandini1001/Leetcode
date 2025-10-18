class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int add=k;
        int maxi=nums[nums.size()-1]+add;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==nums[i+1]){
                add--;
                while(add>=-k){
                    if(nums[i]+add>=maxi) add--;
                    else {
                        maxi=nums[i]+add;
                        break;
                    }
                }
                if(add<-k) cnt++;
            }
            else{
                add=k;
                while(add>=-k){
                    if(nums[i]+add>=maxi) add--;
                    else{
                        maxi=nums[i]+add;
                        break;
                    }
                }
                if(add<-k) cnt++;
            }
        }
        return nums.size()-cnt;
    }
};