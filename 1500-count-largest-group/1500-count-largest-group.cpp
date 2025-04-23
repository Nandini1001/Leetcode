class Solution {
public:
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
        vector<int> count(37, 0); // Max digit sum from 1 to 9999 is 9+9+9+9 = 36

        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            count[sum]++;
        }

        int maxSize = *max_element(count.begin(), count.end());
        int result = count_if(count.begin(), count.end(), [maxSize](int c) { return c == maxSize; });

        return result;
    }
};