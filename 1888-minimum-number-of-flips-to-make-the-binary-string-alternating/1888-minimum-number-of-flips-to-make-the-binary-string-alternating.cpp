class Solution {
public:
    int minFlips(string s) {
        int ans=1e9, cnt=0, n=s.size();
        char change='1';
        for(int j=0;j<s.size();j++){
            if(s[j]!=change) cnt++;
            if(change=='0') change='1';
            else change='0';
        }
        
        ans=min(cnt,n-cnt);
        if(ans==0) return 0;
        change='1';
        for(int i=1;i<n;i++){
            if(s[i-1]!=change) cnt--;
            char last;
            if(change=='0') last=(n%2)?'1':'0';
            else last=(n%2)?'0':'1';
            if(s[(i+n-1)%n]!=last) cnt++;
            if(change=='0') change='1';
            else change='0';
            ans=min(ans,min(cnt,n-cnt));
        }
        return ans;
    }
};


//prev brute force
