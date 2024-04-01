class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty_bottles=0;
        int bottles_drunk=0;
        while(true){
            bottles_drunk+=numBottles;
            empty_bottles+=numBottles;
            numBottles=0;
            if(empty_bottles<numExchange) break;
            while(empty_bottles>=numExchange){
                empty_bottles-=numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return bottles_drunk;
    }
};