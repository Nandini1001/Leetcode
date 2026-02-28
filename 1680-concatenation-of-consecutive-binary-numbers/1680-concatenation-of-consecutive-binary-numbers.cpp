class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=1;
        int next=2, bits=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            if(i==next){
                bits++;
                next*=2;
            }
            ans=((ans<<bits)+i)%mod;
        }
        return ans;
    }
};