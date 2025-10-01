/* Original Solution 1 */
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles < numExchange) {
            return numBottles;
        }
        
        int nextBottles = numBottles / numExchange;
        int subtract = nextBottles * numExchange;
        return subtract + numWaterBottles(numBottles - subtract + nextBottles, numExchange); 
    }
};


/* Original Solution 2 */
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0;
        
        while (numBottles >= numExchange) {
            int mult = numBottles / numExchange;
            
            sum += mult * numExchange;
            numBottles -= mult * numExchange;
            numBottles += mult;
        }
        
        return sum + numBottles;
    }
};