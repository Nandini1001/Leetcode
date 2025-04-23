class Solution {
public:
    int dgtsum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        /*int sumend=(n>9)?9:n;
        int cntbig=0;
        int cntmax=0;
        for(int sum=1;sum<=sumend;sum++) {
            int cnt=1;
            for(int i=1;i<=sum;i++){
                int scddgt=sum-i;
                int no=i*10+scddgt;
                if (no<=n)
                    cnt++;
            }
            if(cnt>cntmax){
                cntmax=cnt;
                cntbig=1;
            }
            else if(cnt==cntmax)
                cntbig++;
        }
        return cntbig;*/
        unordered_map<int,int> mpp;
        int res=0;
        int max=INT_MIN;
        for(int i=1;i<=n;i++){
            int sum=dgtsum(i);
            mpp[sum]++;
            if(mpp[sum]>max){
                max=mpp[sum];
                res=1;
            }
            else if(mpp[sum]==max) res++;
        }
        return res;
    }
};