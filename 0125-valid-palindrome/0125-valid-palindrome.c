bool isPalindrome(char* s) {
    int j=strlen(s)-1,i=0;
    while(i<j)
    {
        if(s[i]<='Z' && s[i]>='A')
            s[i]=s[i]+32;
        if(s[j]<='Z' && s[j]>='A')
            s[j]=s[j]+32;
        if(s[i]>'z' || s[i]<'0' || (s[i]>'9' && s[i]<'a'))
        {
            i++;
            continue;
        }  
        if(s[j]>'z' || s[j]<'0' || (s[j]>'9' && s[j]<'a'))
        {
            j--;
            continue;
        }    
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}