class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxlen=0;
        /*vector<int> hash(256,-1);
        while(r<s.size())
        {
            if(hash[s[r]]!=-1)
            {
                if(hash[s[r]]>=l)
                    l=hash[s[r]]+1;
            }
            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r;
            r++;
        }*/
        vector<int> hash(256,-1);
        while(r<s.size())
        {
            if(hash[s[r]]>=l)
            {
                l=hash[s[r]]+1;
                hash[s[r]]=r;
                r++;
                continue;
            }
            hash[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};