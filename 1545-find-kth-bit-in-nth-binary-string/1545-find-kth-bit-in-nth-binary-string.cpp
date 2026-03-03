class Solution {
public:
    char findKthBit(int n, int k) {
        return fun(n,k);
    }
    char fun(int n, int k){
        if(n==1) return '0';
        int size=pow(2,n)-1;
        if(k==(size/2)+1) return '1';
        if(k<=size/2) return fun(n-1,k);
        char temp=fun(n-1,k-2*(k-(size/2)-1));
        if(temp=='0') return '1';
        return '0';
    }
};