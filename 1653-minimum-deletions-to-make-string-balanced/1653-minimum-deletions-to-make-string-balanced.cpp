class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> pre(n,0);
        for(int i=1;i<s.size();i++){
            if(s[i-1]=='b')
                pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
        }
        int suff=0;
        int ans=1e9;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                ans=min(ans,pre[i]+suff);
                suff++;
            }
        }
        ans=min(ans,suff);
        ans=min(ans,pre[n-1]);
        return (ans==1e9)?0:ans;
    }
};