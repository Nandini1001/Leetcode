class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=1e9, maxprofit=0;
        for(int i:prices){
            minprice=min(minprice, i);
            maxprofit=max(maxprofit,i-minprice);
        }
        return maxprofit;
    }
};