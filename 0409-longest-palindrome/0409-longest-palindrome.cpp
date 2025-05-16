class Solution {
public:
    int longestPalindrome(string s) {
        int one=0,cnt=0;
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
        return cnt;
    }
};