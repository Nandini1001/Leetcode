class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int n=s.size();
        int len=0;
        unordered_map<char, int> mpp;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end())
                if(mpp[s[r]]>=l) l=mpp[s[r]]+1;
            mpp[s[r]]=r;
            len=max(len, r-l+1);
            r++;
        }
        return len;
    }
};