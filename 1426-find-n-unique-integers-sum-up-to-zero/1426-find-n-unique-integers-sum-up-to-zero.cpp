class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans1, ans;
        for(int i=1;i<=n/2;i++)
            ans.push_back(i);
        for(auto it: ans ){
            ans1.push_back(it);
            ans1.push_back(-it);
        }
        if(n%2) ans1.push_back(0);
        return ans1;
    }
};