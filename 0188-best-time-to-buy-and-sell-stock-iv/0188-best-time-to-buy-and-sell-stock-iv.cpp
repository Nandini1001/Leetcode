class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> front(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
                for(int cnt=1;cnt<=k;cnt++){
                    curr[1][cnt]=max(-prices[ind]+front[0][cnt],front[1][cnt]);
                    curr[0][cnt]=max(prices[ind]+front[1][cnt-1],front[0][cnt]);
                }
                front=curr;
            }
        return front[1][k];
    }
};


//space optimisation
//1->buy
//0->not buy