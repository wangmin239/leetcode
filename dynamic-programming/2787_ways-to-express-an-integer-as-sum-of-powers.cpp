/* Original Solution 1 */
class Solution {
public:
    int numberOfWays(int n, int x) {
        const int upLimit = 301;
        vector<vector<int>> memo(n + 1, vector<int>(upLimit + 1, -1));
        function<int(int, int, int)> dfs = [&] (int value, int pow, int start) {
            if (value == 0) {
                return 1;
            }
            
            if (value < 0) {
                return 0;
            }
            
            const int mod = 1e9 + 7;
            int ways = 0;
            for (int i = start; i < upLimit; i++) {
                int multiply = 1;
                for (int j = 0; j < pow; j++) {
                    multiply *= i;
                }
                
                if (multiply > value) {
                    break;
                }
                int id = value - multiply;
                if (memo[id][i + 1] == -1) {
                    memo[id][i + 1] = dfs(value - multiply, pow, i + 1) % mod;
                }
                
                ways += memo[id][i + 1];
                ways %= mod;
            }
            
            return ways;
        };
        
        return dfs(n, x, 1);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int numberOfWays(int n, int x) {
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= val) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % mod;
                }
            }
        }
        return dp[n][n];
    }
};


/* Official Solution 2 */
class Solution {
public:
    int numberOfWays(int n, int x) {
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);
            if (val > n) {
                break;
            }
            for (int j = n; j >= val; j--) {
                dp[j] = (dp[j] + dp[j - val]) % mod;
            }
        }
        return dp[n];
    }
};
