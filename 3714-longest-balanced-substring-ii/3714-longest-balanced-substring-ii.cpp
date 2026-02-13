class Solution {
public:
    int longestBalanced(string s) {
        int single=-1, cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                single=max(single,cnt);
                cnt=1;
            }
            else cnt++;
        }
        single=max(single,cnt);
        int two=max(fun(s,'a','c'),max(fun(s,'a','b'),fun(s,'b','c')));
        int three=-1;
        int cnta=0, cntb=0, cntc=0;
        unordered_map<string,int> mpp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') cnta++;
            else if(s[i]=='b') cntb++;
            else cntc++;
            if(cnta==cntb && cntb==cntc) three=i+1;
            else{
                string diff;
                diff+=to_string(cnta-cntb);
                diff+="-";
                diff+=to_string(cntb-cntc);
                if(mpp.find(diff)!=mpp.end()){
                    three=max(three,i-mpp[diff]);
                }
                else{
                    mpp[diff]=i;
                }
            }
        }
        return max(single,max(two,three));
    }
    int fun(string &s, char f, char d){
        int ans=-1;
        unordered_map<int,int> mpp;
        int cntf=0, cntd=0, start=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==f) cntf++;
            else if(s[i]==d) cntd++;
            else{
                cntf=0, cntd=0;
                mpp.clear();
                start=i;
            }
            if(cntf==cntd){
                ans=max(ans,i-start);
            }
            else{
                int diff=cntf-cntd;
                if(mpp.find(diff)!=mpp.end()){
                    ans=max(ans,i-mpp[diff]);
                }
                else{
                    mpp[diff]=i;
                }
            }
        }
        return ans;
    }
};