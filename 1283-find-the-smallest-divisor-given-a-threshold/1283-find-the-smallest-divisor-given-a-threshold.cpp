class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=*max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(sum(nums,mid)>threshold) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
    long long sum(vector<int>& nums, int divisor){
        long long total=0;
        for(auto i:nums){
            total+=ceil((float)i/divisor);
        }
        return total;
    }
};