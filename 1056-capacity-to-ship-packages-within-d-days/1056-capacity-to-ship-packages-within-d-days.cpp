class Solution {
private:
    int noofdays(vector<int>& weights, int wt)
    {
        int day=1,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>wt)
            {
                day++;
                sum=weights[i];
            }
        }
        return day;
            /*sum+=weights[i];
            if(sum>wt)
            {
                day++;
                sum=0;
                i--;
            }
        }
        return day+1;
            if(sum+weights[i]>wt)
            {
                day++;
                sum=weights[i];
            }
            else
                sum+=weights[i];
        }
        return day;*/
    }
    int findMax(vector<int>& weights)
    {
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++)
            maxi=max(maxi,weights[i]);
        return maxi;
    }
    int sumall(vector<int>& weights)
    {
        int sum=0;
        for(int i=0;i<weights.size();i++)
            sum+=weights[i];
        return sum;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=findMax(weights),high=sumall(weights);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(noofdays(weights,mid)<=days)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};