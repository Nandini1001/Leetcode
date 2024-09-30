int maxProfit(int* prices, int pricesSize) {
    int min=prices[0],profit=0,cost;
    for(int i=1;i<pricesSize;i++)
    {
        cost=prices[i]-min;
        if(cost>profit)
            profit=cost;
        if(min>prices[i])
            min=prices[i];
    }
    return profit;
}