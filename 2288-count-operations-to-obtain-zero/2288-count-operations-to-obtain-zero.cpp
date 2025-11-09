class Solution {
public:
    int countOperations(int num1, int num2) {
        return helper(num1,num2);
    }
    int helper (int n, int m){
        if(n==0 || m==0) return 0;
        if(n>=m)
            return n/m+helper(n%m,m);
        else return m/n+helper (n,m%n);
    }
};


//prev take O(max(num1,num2)) both time and space
//this take O(log(max(num1,num2))) both time and space