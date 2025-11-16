class Solution {
public:
    int numSub(string s) {
        int mod=1e9+7;
        long long one=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                cnt+=((one*(one+1))/2)%mod;
                one=0;
            }
        }
        cnt+=(one*(one+1))/2;
        return cnt;
    }
};