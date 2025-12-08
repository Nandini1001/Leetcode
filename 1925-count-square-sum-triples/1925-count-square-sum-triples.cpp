class Solution {
public:
    int countTriples(int n) {
        long long cnt=0;
        for(int i=1;i<=n;i++){
            int start=1, end=n;
            while(start<end){
                if((start*start)+(end*end)==i*i){
                    cnt+=1;
                    start++;
                    end--;
                }
                else if((start*start)+(end*end)>i*i) end--;
                else start++;
            }
        }
        return (int)cnt*2;
    }
};