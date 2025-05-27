class Solution {
public:
    int differenceOfSums(int n, int m) {
        /*int num2=0,num1=0,i;
        for(i=m;i<=n;i+=m){
            num2+=i;
            int prev=i-m;
            int sum1=((i-1)*(i))/2;
            int sum2=(prev*(prev+1))/2;
            num1+=(sum1-sum2);
        }
        for(int j=i-m+1;j<=n;j++)
            num1+=j;
        return num1-num2;*/
        int num1=0, num2=0;
        for(int i=0;i<=n;i++){
            if(i%m) num1+=i;
            else num2+=i;
        }
        return num1-num2;
    }
};