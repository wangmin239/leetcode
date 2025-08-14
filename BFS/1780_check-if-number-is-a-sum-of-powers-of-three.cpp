/* Original Solution 1 */
class Solution {
public:
    bool checkPowersOfThree(int n) {
        function<bool(int, int)> dfs = [&](int value, int exponent) {
            if (value == 0) {
                return true;
            }
            const int upLimit = 15;
            bool ans = false;
            for (int i = exponent; i < upLimit; i++) {
                int curVal =  static_cast<int>(pow(3, i));
                if (curVal <= value) {
                    ans |= dfs(value - curVal, i + 1);
                } else {
                    break;
                }
            }
            
            return ans;
        };
                    
        return dfs(n, 0); 
    }
};



/* Original Solution 2 */
class Solution {
public:
    bool checkPowersOfThree(int n) {
        const int base = 3;
        const int limit = static_cast<int>(log(n + 1) / log(base));
        vector<int> powValues;
        unordered_set<int> sumSet;
        
        for (int exponent = 0; exponent <= limit; exponent++) {
            powValues.emplace_back(pow(base, exponent));
        }
        
        
        function<void(int, int, int)> backTrace = [&](int num, int index, int sum) {
            if (num == 0) {
                sumSet.insert(sum);
                return;
            }
            
            for (int i = index; i <= limit; i++) {
                backTrace(num - 1, i + 1, sum + powValues[i]);
            }
            return;
        };
        
        
        
        for (int num = 1; num <= limit + 1; num++) {
            backTrace(num, 0, 0);
        }
                
        
        return sumSet.count(n);
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            double exp = log(n + 1) / log(3);
            int intExp = static_cast<int>(exp);
            int value = static_cast<int>(pow(3, intExp));
            n -= value;
            
            if (n >= value) {
                return false;
            }
        }
        
        return n == 0;
    }
};