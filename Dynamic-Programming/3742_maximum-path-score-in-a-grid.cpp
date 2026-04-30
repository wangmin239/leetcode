/* Original Solution 1 */
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector memo(rows, vector(cols, vector<int>(k + 1, -1)));

        auto dfs = [&](int x, int y, int remainK, auto&& self) {
            if (x < 0 || x >= rows || y < 0 || y >= cols || remainK < 0) {
                return INT_MIN;
            }

            int& res = memo[x][y][remainK];
            if (x == rows - 1 && y == cols - 1) {
                if (remainK > 0) {
                    res = grid[x][y];
                } else if (grid[x][y] == 0) {
                    res = 0;
                } else {
                    res = INT_MIN;
                }
                return res;
            }

            if (res != -1) {
                return res;
            }

            remainK -= grid[x][y] > 0;
            res = max(self(x + 1, y, remainK, self),  self(x, y + 1, remainK, self)) + grid[x][y];

            return res;
        };

        int ans = dfs(0, 0, k, dfs);
        return ans < 0 ? -1 : ans;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == INT_MIN)
                        continue;
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] =
                                max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
                        }
                    }
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] =
                                max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }
        return ans < 0 ? -1 : ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector memo(m, vector(n, vector<int>(k + 1, -1)));

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || j < 0 || k < 0) { // 出界或者总花费超了
                return INT_MIN;
            }
            if (i == 0 && j == 0) {
                return 0; // 题目保证 grid[0][0] = 0
            }
            int& res = memo[i][j][k];
            if (res != -1) {
                return res;
            }
            int x = grid[i][j];
            if (x > 0) {
                k--;
            }
            return res = max(dfs(i - 1, j, k), dfs(i, j - 1, k)) + x;
        };

        int ans = dfs(m - 1, n - 1, k);
        return ans < 0 ? -1 : ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        vector f(m + 1, vector(n + 1, vector<int>(K + 2, INT_MIN)));
        ranges::fill(f[0][1].begin() + 1, f[0][1].end(), 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                for (int k = 0; k <= K; k++) {
                    int new_k = k - (x > 0);
                    f[i + 1][j + 1][k + 1] = max(f[i][j + 1][new_k + 1], f[i + 1][j][new_k + 1]) + x;
                }
            }
        }

        int ans = f[m][n][K + 1];
        return ans < 0 ? -1 : ans;
    }
};


/* Official Solution 4 */
class Solution {
    // 64. 最小路径和
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> f(n + 1, INT_MAX);
        f[1] = 0;
        for (auto& row : grid) {
            for (int j = 0; j < n; j++) {
                f[j + 1] = min(f[j], f[j + 1]) + min(row[j], 1); // 值大于 0 的单元格花费 1
            }
        }
        return f[n];
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int K) {
        if (minPathSum(grid) > K) {
            return -1;
        }

        int m = grid.size(), n = grid[0].size();
        K = min(K, m + n - 2); // 至多花费 m+n-2
        vector f(n + 1, vector<int>(K + 2, INT_MIN));
        f[1][1] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                for (int k = min(K, i + j); k >= 0; k--) { // 从 (0,0) 到 (i,j) 至多花费 i+j
                    int new_k = k - (x > 0);
                    f[j + 1][k + 1] = max(f[j + 1][new_k + 1], f[j][new_k + 1]) + x;
                }
            }
        }

        return ranges::max(f[n]);
    }
};