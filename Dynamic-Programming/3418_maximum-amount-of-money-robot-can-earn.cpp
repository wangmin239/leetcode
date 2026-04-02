/* Original Solution 1 */
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows = coins.size();
        int cols = coins.front().size();
        vector<int> dp(cols, 0);
        vector<int> dp1(cols, 0);
        vector<int> dp2(cols, 0);

        dp[0] = coins[0][0];
        dp1[0] = dp2[0] = max(0, coins[0][0]);

        for (int j = 1; j < cols; j++) {
            if (coins[0][j] >= 0) {
                dp1[j] = coins[0][j] + dp1[j - 1];
                dp2[j] = coins[0][j] + dp2[j - 1];
            } else {
                dp2[j] = max(dp1[j - 1], dp2[j - 1] + coins[0][j]);
                dp1[j] = max(dp[j - 1], dp1[j - 1] + coins[0][j]);
            }
            dp[j] = coins[0][j] + dp[j - 1];
        }

        for (int i = 1; i < rows; i++) {
            dp2[0] = max(dp1[0], dp2[0] + coins[i][0]);
            dp1[0] = max(dp[0], dp1[0] + coins[i][0]);
            dp[0] += coins[i][0];
            for (int j = 1; j < cols; j++) {
                int x = coins[i][j];
                if (x < 0) {
                    dp2[j] = max({dp1[j - 1], dp1[j], dp2[j - 1] + x, dp2[j] + x});
                    dp1[j] = max({dp[j - 1], dp[j], dp1[j - 1] + x, dp1[j] + x});
                } else {
                    dp2[j] = max(dp2[j - 1], dp2[j]) + x;
                    dp1[j] = max(dp1[j - 1], dp1[j]) + x;
                }
                dp[j] = max(dp[j - 1], dp[j]) + x;
            }
        }
        return  dp2[cols - 1];
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector memo(m, vector(n, array<int, 3>{INT_MIN, INT_MIN, INT_MIN}));

        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (i >= m || j >= n) {
                return INT_MIN;
            }

            int x = coins[i][j];
            // 到达终点
            if (i == m - 1 && j == n - 1) {
                return k > 0 ? max(0, x) : x;
            }
            
            int res = memo[i][j][k];
            if (res != INT_MIN) {
                return res;
            }
            // 不进行感化
            res = max(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x;
            if (k > 0 && x < 0) {
                // 进行感化
                res = max({res, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1)});
            }
            return memo[i][j][k] = res;
        };

        return dfs(0, 0, 2);
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector dp(m, vector(n, array<int, 3>{INT_MIN / 2, INT_MIN / 2, INT_MIN / 2}));
        
        dp[0][0][0] = coins[0][0];
        for (int k = 1; k <= 2; k++) {
            dp[0][0][k] = max(coins[0][0], 0);
        }
        for (int j = 1; j < n; j++) {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
            for (int k = 1; k <= 2; k++) {
                dp[0][j][k] = max(dp[0][j - 1][k] + coins[0][j], dp[0][j - 1][k - 1] + max(coins[0][j], 0));
            }
        }
        for (int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            for (int k = 1; k <= 2; k++) {
                dp[i][0][k] = max(dp[i - 1][0][k] + coins[i][0], dp[i - 1][0][k - 1] + max(coins[i][0], 0));
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
                for (int k = 1; k <= 2; k++) {
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]) + coins[i][j], 
                                        max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]));
                }
            }
        }
        
        return dp[m - 1][n - 1][2];
    }
};



/* Official Solution 3 */
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins[0].size();
        vector dp(n + 1, vector<int>(3, INT_MIN / 2));
        
        for (int i = 0; i < 3; i++) {
            dp[1][i] = 0;
        }
        for (auto& row : coins) {
            for (int j = 1; j <= n; j++) {
                int x = row[j - 1];
                dp[j][2] = max({dp[j - 1][2] + x, dp[j][2] + x, dp[j - 1][1], dp[j][1]});
                dp[j][1] = max({dp[j - 1][1] + x, dp[j][1] + x, dp[j - 1][0], dp[j][0]});
                dp[j][0] = max(dp[j - 1][0], dp[j][0]) + x;
            }
        }

        return dp[n][2];
    }
};