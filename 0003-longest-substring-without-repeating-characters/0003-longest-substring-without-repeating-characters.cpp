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
        unordered_map<char,int> mpp;
        while(r<s.size())
        {
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l)
            {
                l=mpp[s[r]]+1;
                mpp[s[r]]=r;
                r++;
                continue;
            }
            mpp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};