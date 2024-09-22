/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int c=0,j,i;
    int *digitplusone=(int*)malloc((digitsSize+1)*sizeof(int));
    for(int i=0;i<digitsSize;i++)
    {
        if(digits[i]!=9)
        {
            c=1;
            break;
        }
    }
    if(c==0)
    {
        j=digitsSize;
        *returnSize=digitsSize+1;
    }
    else
    {
        j=digitsSize-1;
        *returnSize=digitsSize;
    }
    i=digitsSize-1;
    if(digits[i]!=9)
    {
        digitplusone[j]=digits[i]+1;
        j--;
        for(i=digitsSize-2;i>=0;i--,j--)
            digitplusone[j]=digits[i];
    }
    else
    {
        digitplusone[j]=0;
        j--;
        if(digitsSize==1)
        {    digitplusone[0]=1;
            return digitplusone;}
        for(i=digitsSize-2;i>=0;i--,j--)
        {
            if(digits[i]!=9)
            {
                digitplusone[j]=digits[i]+1;
                j--;
                i--;
                for(;i>=0;i--,j--)
                    digitplusone[j]=digits[i];
                break;
            }
            else
            {
                digitplusone[j]=0; 
            }
        }
        if(j>=0)
        digitplusone[j]=1;
    }
    return digitplusone;
    /*int *digitplusone=(int*)malloc((digitsSize+1)*sizeof(int));
    long long int no,num=0,i,c=0;
    for(i=0;i<digitsSize;i++)
    {
        num=num*10+digits[i];
    }
    num=num+1;
    no=num;
    while(num>0)
    {
        c++;
        num=num/10;
    }
    *returnSize=c;
    for(i=c-1;i>=0;i--)
    {
        *(digitplusone+i)=no%10;
        no=no/10;
    }
    return digitplusone;*/
}