class Solution {
public:
    int differenceOfSums(int n, int m) {
        /*
        the time complexity of the commented code is better than the uncommented code 
        when m is large. In the worst case (m = 1), both are equal at O(n)
        
        int num2=0,num1=0,i;
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


        //int num1=0, num2=0;
        int num1=0;
        for(int i=0;i<=n;i++){
            if(i%m) num1+=i;
            //else num2+=i;
            else num1-=i;
        }
        //return num1-num2;
        return num1;
    }
};