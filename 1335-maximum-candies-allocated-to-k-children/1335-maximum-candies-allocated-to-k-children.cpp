class Solution {
private:
    bool possible(vector<int>& candies, int maxi, long long k)
    {
        long long child=0;
        for(auto i:candies)
        {
            child+=(i/maxi);
            if(child>=k) return true;
        }
        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1, high=*max_element(candies.begin(),candies.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(candies,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};