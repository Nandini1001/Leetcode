class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num2=0,num1=0,i;
        for(i=m;i<=n;i+=m){
            num2+=i;
            int prev=i-m;
            int sum1=((i-1)*(i))/2;
            int sum2=(prev*(prev+1))/2;
            num1+=(sum1-sum2);
        }
        //cout<<num1<<" "<<i<<" ";
        for(int j=i-m+1;j<=n;j++)
            num1+=j;
        cout<<num1<<" "<<num2;
        return num1-num2;
    }
};