class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> primes={2,3,5,7,11,13,17,19,23,29,31};
        int cnt=0;
        for(int i=left;i<=right;i++){
            int noofsetbits=__builtin_popcount(i);
            if(find(primes.begin(), primes.end(), noofsetbits) != primes.end())
                cnt++;
        }
        return cnt;
    }
};