class Solution {
public:
    int minimumOneBitOperations(int n) {
        //return helper(n);
        if (n == 0) {
            return 0;
        }
        
        int k = 0;
        int curr = 1;
        while (curr * 2 <= n) {
            curr *= 2;
            k++;
        }
        
        return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ curr);
    }
    /*int helper(int n){
        if(n==0) return 0;
        int first=1+helper(n^1);
        int pos = 1;
        int no=n;
        while ((n & 1) == 0) {
            n >>= 1;
            pos++;
        }
        int second=1+helper(no^(1<<pos));
        return min(first,second);
    }*/
};