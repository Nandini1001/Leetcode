class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0,ind1=-1,ind2=-1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt>2) return false;
                if(ind1==-1) ind1=i;
                else ind2=i;
            }
        }
        if((cnt==2 && s1[ind1]==s2[ind2] && s1[ind2]==s2[ind1]) || cnt==0) return true;
        return false;
    }
};