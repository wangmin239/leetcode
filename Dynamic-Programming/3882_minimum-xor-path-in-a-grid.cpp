
/* Original Solution  1 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        int minVal = INT_MAX;

        auto dfs = [&](int x, int y, int curVal, auto&& self) {
            if (x == m && y == n - 1 || x == m - 1 && y == n) {
                minVal = min(minVal, curVal);
            }

            if (x >= m || y >= n) {
                return;
            }

            self(x + 1, y, curVal ^ grid[x][y], self);
            self(x, y + 1, curVal ^ grid[x][y], self);

            return;
        };

        dfs(0, 0, 0, dfs);
        return minVal;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<array<bool, 1024>> dp(n);
        array<bool, 1024> next{};

        dp[0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                const int value = grid[i][j];
                next.fill(false);

                for (int k = 0; k < 1024; k++) {
                    if (dp[j][k] || (j > 0 && dp[j - 1][k])) {
                        next[k ^ value] = true;
                    }
                }

                dp[j] = next;
            }
        }

        for (int k = 0; k < 1024; k++) {
            if (dp[n - 1][k]) {
                return k;
            }
        }

        return -1;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // 异或和不会超过所有元素的 OR
        int or_all = 0;
        for (auto& row : grid) {
            for (int x : row) {
                or_all |= x;
            }
        }

        vector vis(m, vector(n, vector<int8_t>(or_all + 1)));
        int ans = INT_MAX;

        auto dfs = [&](this auto&& dfs, int i, int j, int xor_val) -> void {
            // 最优性剪枝：如果答案已经最小（等于 0），那么不再搜索
            if (ans == 0 || i < 0 || j < 0 || vis[i][j][xor_val]) {
                return;
            }
            vis[i][j][xor_val] = true;
            xor_val ^= grid[i][j];
            if (i == 0 && j == 0) {
                ans = min(ans, xor_val);
                return;
            }
            dfs(i - 1, j, xor_val);
            dfs(i, j - 1, xor_val);
        };

        dfs(m - 1, n - 1, 0);
        return ans;
    }
};
