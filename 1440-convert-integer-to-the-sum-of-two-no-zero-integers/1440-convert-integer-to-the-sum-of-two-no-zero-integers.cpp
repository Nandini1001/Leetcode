class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=1, b=n-1;
        while(!checkzero(a) || !checkzero(b)){
            a++;
            b--;
        }
        return{a,b};
    }
    bool checkzero(int n){
        while(n>0){
            int rem=n%10;
            if(rem==0){
                return false;
            }
            n=n/10;
        }
        return true;
    }
};