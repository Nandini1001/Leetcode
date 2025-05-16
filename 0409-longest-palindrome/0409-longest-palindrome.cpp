class Solution {
public:
    int longestPalindrome(string s) {
        /*int one=0,cnt=0;
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        vector<int> freq;
        for(auto it:mpp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());
        for(auto it:freq){
            if((it & 1)){
                if(one)
                    cnt+=(it-1);
                else{
                    cnt+=it;
                    one=1;
                }
            }
            else if(!(it & 1))
                cnt+=it;
        }
        return cnt;*/
        int cnt=0,odd=0;
        vector<int>lower(26,0);
        vector<int> upper(26,0);
        for(char c:s){
            if(c>='a')
                lower[c-'a']++;
            else
                upper[c-'A']++;
        }
        for(int i=0;i<26;i++){
            if(lower[i]&1){
                cnt+=lower[i]-1;
                odd=1;
            }
            else cnt+=lower[i];

            if(upper[i]&1){
                cnt+=upper[i]-1;
                odd=1;
            }
            else cnt+=upper[i];
        }
        return cnt+odd;
    }
};