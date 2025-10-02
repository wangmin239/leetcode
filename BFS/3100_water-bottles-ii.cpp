/* Original Solution 1 */
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        function<int(int, int, int)> dfs = [&](int emptyBottles, int fullBottles, int numExchange) {
            if (emptyBottles >= numExchange) {
                return dfs(emptyBottles - numExchange, fullBottles + 1, numExchange + 1);
            }
            if (emptyBottles + fullBottles < numExchange) {
                return fullBottles;
            }
            return fullBottles + dfs(emptyBottles + fullBottles, 0, numExchange);
        };
        
        return dfs(0, numBottles, numExchange);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        for (int empty = numBottles; empty >= numExchange; numExchange++) {
            ans++;
            empty -= numExchange - 1;
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int a = 1;
        int b = 2 * numExchange - 3;
        int c = -2 * numBottles;
        double delta = (double)b * b - 4.0 * a * c;
        int t = (int)ceil(( -b + sqrt(delta)) / (2.0 * a));
        return numBottles + t - 1;
    }
};
