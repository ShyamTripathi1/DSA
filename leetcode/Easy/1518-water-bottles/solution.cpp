class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank =  numBottles;
        while(numBottles >=  numExchange){
            int exchanged = numBottles/numExchange;
            int extra = numBottles%numExchange;
            drank += exchanged;
            numBottles = exchanged + extra; 
        }
        return drank;
    }
};
