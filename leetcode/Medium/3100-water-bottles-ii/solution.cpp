class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            numBottles += 1; 
            drank++;
            numExchange++;
        }
        
        return drank;
    }
};

