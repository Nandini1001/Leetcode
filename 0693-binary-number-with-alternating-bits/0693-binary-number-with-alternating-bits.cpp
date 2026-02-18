class Solution {
public:
    bool hasAlternatingBits(int n) {
        long isallone=n^(n>>1);
        return (isallone & (isallone+1))==0;
    }
};