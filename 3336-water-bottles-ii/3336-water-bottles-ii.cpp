class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles, drunk=numBottles;
        while(empty>=numExchange){
                empty=empty-numExchange;
                numExchange++;
                drunk++;
                empty++;
        }
        return drunk;
    }
};