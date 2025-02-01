class Solution {
private:
    int possible(vector<int>& bloomDay, int m, int k, int day)
    {
        int n=bloomDay.size(),cnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=day)
            {
                cnt++;
            }
            else
            {
                ans+=cnt/k;
                cnt=0;
                if(ans>=m)
                    return 1;
            }
        }
        ans+=cnt/k;
        return ans>=m;
        /*if(ans>=m)
            return 1;
        return 0;*/
    }
    int findmin(vector<int>& bloomDay)
    {
        int ans=INT_MAX,n=bloomDay.size();
        for(int i=0;i<n;i++)
            ans=min(ans,bloomDay[i]);
        return ans;
    }
    int findmax(vector<int>& bloomDay)
    {
        int ans=INT_MIN,n=bloomDay.size();
        for(int i=0;i<n;i++)
            ans=max(ans,bloomDay[i]);
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size(),low=findmin(bloomDay),high=findmax(bloomDay);
        long long val=long(m)*k;
        if(n<val) return -1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(bloomDay,m,k,mid)==1)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};