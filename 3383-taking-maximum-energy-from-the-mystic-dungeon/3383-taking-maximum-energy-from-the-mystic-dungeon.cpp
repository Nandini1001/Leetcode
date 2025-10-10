class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> prefixsum(n);
        prefixsum=energy;
        //int maxitimes=n/k;
        for(int i=n-1;i>=0;i--){
          //  for(int j=1;j<=maxitimes;j++){
                int ind=i+k;
                if(ind<n){
                     prefixsum[i]+=prefixsum[ind];
                    }
        //    }
        }
        int maxi=INT_MIN;
        for(auto it:prefixsum){
            maxi=max(maxi,it);
        }
        return maxi;
    }
};