class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int remain = 0;
        return dfs(numBottles, numExchange, remain);
    }
    
    int dfs(int numBottles, int numExchange, & remain) {
        if (numBottles == 0) {
            return 0;
        }
        
        int exchangeBottles = (numBottles + remain) / numExchange;
        remain = (numBottles + remain) % numExchange;
        return numBottles + dfs(exchangeBottles, numExchange, remain);
    }
};



class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0;
        int remain = 0;
        
        while (numBottles != 0) {
            sum += numBottles;
            int change = (numBottles + remain) / numExchange;
            remain = (numBottles + remain) % numExchange;
            numBottles = change;
        }
        
        return sum;
    }
};

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottle = numBottles, ans = numBottles;
        while (bottle >= numExchange) {
            bottle -= numExchange;
            ++ans;
            ++bottle;
        }
        return ans;
    }
};


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles : numBottles;
    }
};
