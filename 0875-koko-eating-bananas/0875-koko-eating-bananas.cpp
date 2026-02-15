class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(noofhr(piles,mid)>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
    long long noofhr(vector<int>& piles, int k){
        long long totalhr=0;
        for(int i=0;i<piles.size();i++){
            totalhr+=ceil((double)piles[i]/k);
        }
        return totalhr;
    }
};