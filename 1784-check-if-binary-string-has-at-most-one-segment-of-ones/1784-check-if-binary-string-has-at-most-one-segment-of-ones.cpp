class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size()==1) return true;
        int flag=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0') flag=1;
            if(flag && s[i]=='1') return false;
        }
        return true;
    }
};