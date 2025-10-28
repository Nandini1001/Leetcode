class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int frontbuy=0, frontnotbuy=0, currbuy=0, currnotbuy=0;
        for(int ind=n-1;ind>=0;ind--){
            currbuy=max(-prices[ind]+frontnotbuy,frontbuy);
            currnotbuy=max(prices[ind]+frontbuy,frontnotbuy);
            frontbuy=currbuy;
            frontnotbuy=currnotbuy;
        }
        return frontbuy;
    }
};


//tabulation && space optimisation from 2 1D arrays to 4 variables
//1->buy
//0->not buy