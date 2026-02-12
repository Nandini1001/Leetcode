class Solution {
public:
    int longestBalanced(string s) {
        if(s.size()==0) return 0;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            unordered_map<int,int> mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                int freq=mpp[s[j]];
                int flag=1;
                for(auto it:mpp){
                    if(it.second!=freq){
                        flag=0;
                        break;
                    }
                }
                if(flag) maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};