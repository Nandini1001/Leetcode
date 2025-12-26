class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> maxpenalty(customers.size()+1,0);
        int cnt=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N')    cnt++;
            maxpenalty[i+1]=cnt;
        }
        cnt=0;
        for(int i=customers.size()-1;i>=0;i--){
            if(customers[i]=='Y') cnt++;
            maxpenalty[i]+= cnt;
        }
        int minpenalty=INT_MAX, ans=-1;
        for(int i=0;i<=customers.size();i++){
            if(minpenalty>maxpenalty[i]){
                minpenalty=maxpenalty[i];
                ans=i;
            }
        }
        return ans;
    }
};