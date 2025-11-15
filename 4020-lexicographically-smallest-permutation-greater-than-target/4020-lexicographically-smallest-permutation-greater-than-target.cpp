class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans;
        map<char,int> mpp;
        for(char i:s){
            mpp[i]++;
        }

        int i=0;
        // Match as long as possible
        for(i=0;i<target.size();i++){
            if(mpp.find(target[i])!=mpp.end()){
                ans+=target[i];
                mpp[target[i]]--;
                if(mpp[target[i]]==0) mpp.erase(target[i]);
            }
            else break;
        }

        // Try to increase at position i
        int flag=0;
        if(i < target.size()) {
            for(char c=target[i]+1; c<='z'; c++){
                if(mpp.find(c)!=mpp.end()){
                    flag=1;
                    ans+=c;
                    if(--mpp[c]==0) mpp.erase(c);
                    break;
                }
            }
        }

        // If not possible, backtrack
        if(!flag){
            for(i=i-1;i>=0;i--){
                mpp[target[i]]++;
                ans.pop_back();
                for(char c=target[i]+1; c<='z'; c++){
                    if(mpp.find(c)!=mpp.end()){
                        flag=1;
                        ans+=c;
                        if(--mpp[c]==0) mpp.erase(c);
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag) return "";
        }

        // Append rest in sorted order
        for(auto it : mpp){
            while(it.second--) ans += it.first;
        }

        return ans;
    }
};


//my logic only
