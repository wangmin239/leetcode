/* Original Solution 1, Time Limit Exceeded 12 / 81 testcases passed */
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        int leftParenthese = 0;

        auto dfs = [&](int x, int y, int leftParenthese, auto&& self) {
            if (x >= rows || y >= cols) {
                return false;
            }

            if (grid[x][y] == '(') {
                ++leftParenthese;
            } else {
                --leftParenthese;
            }

            if (leftParenthese < 0) {
                return false;
            }

            if (x == rows - 1 && y == cols - 1 && leftParenthese == 0) {
                return true;
            }


            bool ans = self(x, y + 1, leftParenthese, self);

            ans |= self(x + 1, y, leftParenthese, self);

            return ans;
        };

        return dfs(0, 0, 0, dfs);
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        const int pathLen = n + m - 1;

        if (pathLen % 2 == 1) {
            return false;
        }
        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')') {
            return false;
        }

        vector<vector<bitset<201>>> dp(n, vector<bitset<201>>(m));

        dp[0][0].set(1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const int change = grid[i][j] == '(' ? 1 : -1;

                if (i > 0) {
                    if (change == 1) {
                        dp[i][j] |= dp[i - 1][j] << 1;
                    } else {
                        dp[i][j] |= dp[i - 1][j] >> 1;
                    }
                }

                if (j > 0) {
                    if (change == 1) {
                        dp[i][j] |= dp[i][j - 1] << 1;
                    } else {
                        dp[i][j] |= dp[i][j - 1] >> 1;
                    }
                }
            }
        }

        return dp[n - 1][m - 1].test(0);
    }
};


/* Official Solution 2 */
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n) % 2 == 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        vector vis(m, vector(n, vector<int8_t>((m + n + 1) / 2)));

        auto dfs = [&](this auto&& dfs, int x, int y, int c) -> bool {
            if (c > m - x + n - y - 1) { // 剪枝：即使后面都是 ')' 也不能把 c 减为 0
                return false;
            }
            if (x == m - 1 && y == n - 1) { // 终点
                return c == 1; // 上面提前判断了，终点一定是 ')'
            }

            if (vis[x][y][c]) {
                return false;
            }
            vis[x][y][c] = true;

            c += grid[x][y] == '(' ? 1 : -1;
            if (c < 0) { // 右括号比左括号还多
                return false;
            }
            return x < m - 1 && dfs(x + 1, y, c) || // 往下
                   y < n - 1 && dfs(x, y + 1, c);   // 往右
        };

        return dfs(0, 0, 0); // 起点
    }
};
