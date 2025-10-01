class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink=numBottles;
        while(1){
            int neww=numBottles/numExchange;
            if(neww==0) break;
            int rem=numBottles%numExchange;
            numBottles=neww+rem;
            drink+=neww;
        }
        return drink;
    }
};