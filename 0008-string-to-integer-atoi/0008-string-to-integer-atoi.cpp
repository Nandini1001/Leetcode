class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int i=0;
        long long ans=0;
        for(;i<s.size();i++){
            if(s[i]!=' ')
                break;
        }
        if(s[i]=='+') {
            sign=1;
            i++;
        }
        else if(s[i]=='-'){
            sign=-1;
            i++;
        }
        for(;i<s.size();i++){
            if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' 
            || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
            {
                ans=ans*10+s[i]-'0';
                if(sign*ans>INT_MAX) return INT_MAX;
                if(sign*ans<INT_MIN) return INT_MIN;
            }
            else break;
        }
        if(sign==1) return ans;
        return sign*ans;
    }
};