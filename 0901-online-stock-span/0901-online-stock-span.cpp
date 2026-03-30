class StockSpanner {
public:
    vector<int> stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int total=0;
        for(int i=stock.size()-1; i>=0; i--){
            if(stock[i]<=price) total++;
            else break;
        }
        stock.push_back(price);
        return total+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */