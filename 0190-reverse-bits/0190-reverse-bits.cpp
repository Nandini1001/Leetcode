class Solution {
public:
    int reverseBits(int n) {
        if(n==0) return 0;
        int rtmost=(n&(n-1))^n;
        int pos_of_rtmost=log2(rtmost);
        return pow(2,31-pos_of_rtmost)+reverseBits(n&(n-1));
    }
};