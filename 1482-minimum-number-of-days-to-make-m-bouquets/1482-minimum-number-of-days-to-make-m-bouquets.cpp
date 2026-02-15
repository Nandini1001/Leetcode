class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(noofbouquet(bloomDay, mid, m, k)>=m) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int noofbouquet(vector<int>& bloomDay, int day, int m, int k){
        int total=0, flower=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                flower++;
            }
            else{
                total+=flower/k;
                flower=0;
            }
        }
        total+=flower/k;
        return total;
    }
};