class Solution {
private:
    double findhr(vector<int>& piles, int k)
    {
        int n=piles.size();
        double totalhr=0;
        for(int i=0;i<n;i++)
        {
            totalhr+=ceil((double)piles[i]/(double)k);
        }
        return totalhr;
    }
    int findMax(vector<int>& piles)
    {
        int ans=INT_MIN,n=piles.size();
        for(int i=0;i<n;i++)
            ans=max(ans,piles[i]);
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        double totalhr;
        while(low<=high)
        {
            int mid=(low+high)/2;
            totalhr=findhr(piles,mid);
            if(totalhr<=h)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};