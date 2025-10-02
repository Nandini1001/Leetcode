class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles, drunk=numBottles,full=0;
        while(true){
            if(empty>=numExchange){
                full++;
                empty=empty-numExchange;
                numExchange++;
            }
            else if(full){
                drunk+=full;
                empty+=full;
                full=0;
            }
            else return drunk;
        }
        return drunk;
    }
};