class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i:arr){
            mpp[i]++;
        }
        int maxi=INT_MIN;
        for(auto it:mpp){
            if(it.first==it.second){
                maxi=max(maxi,it.first);
            }
        }
        if(maxi==INT_MIN) return -1;
        return maxi;
    }
};