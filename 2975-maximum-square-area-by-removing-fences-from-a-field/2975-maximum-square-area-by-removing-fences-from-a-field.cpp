class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1e9+7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set<int> st;
        for(int i=0;i<hFences.size()-1;i++){
            for(int j=i+1;j<hFences.size();j++){
                st.insert(abs(hFences[i]-hFences[j]));
            }
        }
        long long maxside=0;
        for(int i=0;i<vFences.size()-1;i++){
            for(int j=i+1;j<vFences.size();j++){
                if(st.find(abs(vFences[i]-vFences[j]))!=st.end())
                    maxside=max(maxside,(long long)abs(vFences[i]-vFences[j]));
            }
        }
        return maxside==0?-1:(int)((maxside*maxside)%mod);
    }
};