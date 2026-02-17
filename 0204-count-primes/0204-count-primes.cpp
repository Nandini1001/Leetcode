class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n,1);
        int cnt=0;
        sieveoferatosthenes(primes);
        for(int i=2;i<n;i++){
            if(primes[i]==1) cnt++;
        }
        return cnt;
    }
    void sieveoferatosthenes(vector<int>& primes){
        int n=primes.size();
        for(int i=2;i*i<n;i++){
            if(primes[i]){
                for(int j=i*i;j<n;j+=i)
                    primes[j]=0;
            }
        }
    }
};