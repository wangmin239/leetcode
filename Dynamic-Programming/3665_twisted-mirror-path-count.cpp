/* Original Solution 1, 220 / 521 testcases passed */
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        const int mod = 1e9 + 7;
        enum Dir {
            right = 0,
            down = 1,
            maxDir
        };

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        dp[0][0] = 1;

        for (int i = 1; i < cols; i++) {
            if (grid[0][i] == 0) {
                dp[0][i] = dp[0][i - 1];
            } else {
                dp[0][i] = dp[0][i - 1];
                break;
            }
        }

        for (int i = 1; i < rows; i++) {
            if (grid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = dp[i - 1][0];
                break;
            }
        }


        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (grid[i][j] == 0) {
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                    dp[i][j] %= mod;
                    continue;
                }

                dp[i][j] = 0;

                if (i + 1 < rows) {
                    dp[i + 1][j] += dp[i][j - 1];
                }

                if (j + 1 < cols) {
                    dp[i - 1][j + 1] += dp[i - 1][j];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};


/* Official Solution 1 */
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();

        vector<array<long long, 2>> f(n, {0, 0});
        f[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        f[j][0] = (f[j][0] + f[j][1]) % MOD;
                    } else {
                        f[j][0] = f[j][1];
                    }
                }

                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        f[j][1] = (f[j - 1][0] + f[j - 1][1]) % MOD;
                    } else {
                        f[j][1] = f[j - 1][0];
                    }
                }
            }
        }

        return (f[n - 1][0] + f[n - 1][1]) % MOD;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        constexpr int MOD = 1'000'000'007;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<array<long long, 2>>> f(
            m, vector<array<long long, 2>>(n, {0, 0})
        );

        f[0][0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
                    } else {
                        f[i][j][0] = f[i - 1][j][1];
                    }
                }

                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1]) % MOD;
                    } else {
                        f[i][j][1] = f[i][j - 1][0];
                    }
                }
            }
        }

        return (f[m - 1][n - 1][0] + f[m - 1][n - 1][1]) % MOD;
    }
};
