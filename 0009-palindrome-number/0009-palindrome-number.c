bool isPalindrome(int x) {
    if(x<0)
        return false;
    int num=x,lastdgt;
    long rev=0;
    while(x>0)
    {
        lastdgt=x%10;
        rev=rev*10+lastdgt;
        x=x/10;
    }
    if(rev==num)
        return true;
    return false;
}