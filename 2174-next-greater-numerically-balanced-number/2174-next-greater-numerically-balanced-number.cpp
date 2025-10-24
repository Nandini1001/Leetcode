class Solution {
public:
    int nextBeautifulNumber(int n) {
        while(1){
            if(isBeautiful(++n)) return n;
        }
        return 0;
    }
    bool isBeautiful(int n){
        vector<int> freq(10,0);
        while(n>0){
            int lastdgt=n%10;
            freq[lastdgt]++;
            n/=10;
        }
        for(int i=0;i<10;i++){
            if(freq[i]!=0 && freq[i]!=i) return false;
        }
        return true;
    }
};