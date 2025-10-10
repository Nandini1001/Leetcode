class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(i+k<n)
                energy[i]+=energy[i+k];
            maxi=max(maxi,energy[i]);
        }
        return maxi;
    }
    
};
//same as prev accepted
//TC: O(n)
//SC: O(1)