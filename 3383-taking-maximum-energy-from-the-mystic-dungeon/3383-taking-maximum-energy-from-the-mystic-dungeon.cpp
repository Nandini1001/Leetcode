class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> prefixsum(n);
        prefixsum=energy;
        for(int i=n-1;i>=0;i--){
            int ind=i+k;
            if(ind<n)
                prefixsum[i]+=prefixsum[ind];
        }
        int maxi=INT_MIN;
        for(auto it:prefixsum){
            maxi=max(maxi,it);
        }
        return maxi;
    }
    
};
//same as prev accepted
//TC: O(n)
//SC: O(n)