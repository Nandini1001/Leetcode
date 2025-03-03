class Solution {
private:
    int fun(int n)
    {
        vector<int> prime(n+1,1);
        int cnt=0;
        for(int i=2;i<(n+1);i++) prime[i]=1;
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                    prime[j]=0;
            }
        }
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==1) cnt++;
        }
        return cnt;
    }
public:
    int countPrimes(int n) {
        return fun(n-1);
    }
};