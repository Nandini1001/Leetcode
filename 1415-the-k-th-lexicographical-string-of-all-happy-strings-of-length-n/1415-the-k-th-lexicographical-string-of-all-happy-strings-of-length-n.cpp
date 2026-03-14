class Solution {
public:
    string getHappyString(int n, int k) {
        string s="";
        int kk=0;
        helper(s,k,n,0,kk,'d');
        return s;
    }
    bool helper(string &s, int k, int n, int nn, int &kk, char prev){
        if(nn==n){
            kk++;
            if(kk==k) return true;
            return false;
        }        
        for(char c='a'; c<='c';c++){
            if(c!=prev){
                s+=c;
                if(helper(s,k,n,nn+1,kk,c)) return true;
                s.pop_back();
            }
        }
        return false;
    }
};