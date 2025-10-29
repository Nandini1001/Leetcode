class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> front(2,0), curr(2,0);
        front[0]=front[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            curr[1]=max(-prices[ind]-fee+front[0],front[1]);
            curr[0]=max(prices[ind]+front[1],front[0]);
            front=curr;
        }
        return front[1];
    }
};


//tabulation && space optimisation from 2Darray to 2 1D arrays
//1->buy
//0->not buy
//either can apply fees in buy or sell
