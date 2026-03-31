class Solution {
public:
    string generateString(string str1, string str2) {
        int s1=str1.size(), s2=str2.size();
        string ans(s1+s2-1, '$');
        vector<int> change(s1+s2-1, 0);
        for(int i=0;i<str1.size();i++){
            if(str1[i]=='T'){
                for(int j=0; j<s2; j++){
                    if(ans[i+j]!='$' && ans[i+j]!=str2[j]) return "";
                    ans[i+j]=str2[j];
                }
            }
        }
        for(int i=0;i<s1+s2-1;i++){
            if(ans[i]=='$'){
                ans[i]='a';
                change[i]=1;
            }
        }
        for(int i=0; i<s1; i++){
            if(str1[i]=='F'){
                int flag1=1;
                for(int j=0; j<s2; j++){
                    if(ans[i+j]!=str2[j]){
                        flag1=0;
                        break;
                    }
                }
                if(flag1){
                    int j=i+s2-1, flag2=1;
                    while(j>=i){
                        if(change[j]){
                            ans[j]='b';
                            flag2=0;
                            break;
                        }
                        j--;
                    }
                    if(flag2) return "";
                }
            }
        }
        return ans;
    }
};