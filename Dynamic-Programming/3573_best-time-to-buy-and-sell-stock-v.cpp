/* Official Solution 1 */
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>>memo(n, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));

        function<long long(int, int, int)> dfs = [&](int i, int j, int state) -> long long {
            if (j == 0) {
                return 0;
            }
            if (i == 0) {
                return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
            }
            if (memo[i][j][state] != -1) {
                return memo[i][j][state];
            }
            
            int p = prices[i];
            long long res;
            if (state == 0) {
                res = max(dfs(i - 1, j, 0), max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p));
            } else if (state == 1) {
                res = max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
            } else {
                res = max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
            }
            memo[i][j][state] = res;
            
            return res;
        };

        return dfs(n - 1, k, 0);
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(3, 0)));
        // 初始化第 0 天的状态
        for (int j = 1; j <= k; j++) {
            dp[0][j][1] = -prices[0];
            dp[0][j][2] = prices[0];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i]));
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);                
            }
        }
        
        return dp[n - 1][k][0];
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(3));
        // 初始化第 0 天的状态 
        for (int j = 1; j <= k; j++) {
            dp[j][1] = -prices[0];
            dp[j][2] = prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = k; j > 0; j--) {
                dp[j][0] = max(dp[j][0], max(dp[j][1] + prices[i], dp[j][2] - prices[i]));
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
                dp[j][2] = max(dp[j][2], dp[j - 1][0] + prices[i]);  
            }
        }
        
        return dp[k][0];
    }
};


/* Official Solution 4 */
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<array<long long, 3>> f(k + 2, {LLONG_MIN / 2, LLONG_MIN / 2, LLONG_MIN / 2});
        for (int j = 1; j <= k + 1; j++) {
            f[j][0] = 0;
        }
        for (int p : prices) {
            for (int j = k + 1; j > 0; j--) {
                // f[j][0] = max({f[j][0], f[j][1] + p, f[j][2] - p}); 这种写法比下面的慢
                f[j][0] = max(f[j][0], max(f[j][1] + p, f[j][2] - p));
                f[j][1] = max(f[j][1], f[j - 1][0] - p);
                f[j][2] = max(f[j][2], f[j - 1][0] + p);
            }
        }
        return f[k + 1][0];
    }
};
