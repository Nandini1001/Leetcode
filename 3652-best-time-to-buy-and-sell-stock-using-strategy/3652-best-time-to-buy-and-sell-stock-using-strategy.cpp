class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans=0, sum=0;
        for(int i=0;i<prices.size();i++)
            sum+=prices[i]*strategy[i];
        ans=sum;
        for(int i=0;i<k/2;i++){
            if(strategy[i]==-1){
                sum+=prices[i];
            }
            else if(strategy[i]==1)
                sum-=prices[i];
            if(strategy[i+(k/2)]==-1)
                sum+=2*prices[i+(k/2)];
            else if(strategy[i+(k/2)]==0)
                sum+=prices[i+(k/2)];
        }
        ans=max(ans,sum);
        for(int i=1;i<=prices.size()-k;i++){
            sum+=prices[i-1]*strategy[i-1];
            if(strategy[i+k-1]==-1)
                sum+=2*prices[i+k-1];
            else if(strategy[i+k-1]==0)
                sum+=prices[i+k-1];
            sum-=prices[i-1+(k/2)];
            ans=max(ans,sum);
        }
        return ans;
    }
};