/* Official Solution 1 */
class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int memo[m][n][4][2];
        memset(memo, -1, sizeof(memo));
        
        function<int(int, int, int, bool, int)> dfs = [&](int cx, int cy, int direction, bool turn, int target) -> int {
            int nx = cx + dirs[direction][0];
            int ny = cy + dirs[direction][1];
            /* 如果超出边界或者下一个节点值不是目标值，则返回 */
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
                return 0;
            }
            if (memo[nx][ny][direction][turn] != -1) {
                return memo[nx][ny][direction][turn];
            }

            /* 按照原来的方向继续行走 */
            int maxStep = dfs(nx, ny, direction, turn, 2 - target);
            if (turn) {
                /* 顺时针旋转 90 度转向 */
                maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false, 2 - target));
            }
            memo[nx][ny][direction][turn] = maxStep + 1;
            return maxStep + 1;
        };
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        res = fmax(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }

        return res;
    }
};


/* Official Solution 2 */
class Solution {
    static constexpr int DIRS[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector memo(m, vector<array<array<int, 2>, 4>>(n));

        auto dfs = [&](this auto&& dfs, int i, int j, int k, bool can_turn, int target) -> int {
            i += DIRS[k][0];
            j += DIRS[k][1];
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target) {
                return 0;
            }
            int& res = memo[i][j][k][can_turn];
            if (res) {
                return res;
            }
            res = dfs(i, j, k, can_turn, 2 - target) + 1;
            if (can_turn) {
                int maxs[4] = {m - i, j + 1, i + 1, n - j}; // 理论最大值（走到底）
                k = (k + 1) % 4;
                // 优化二：如果理论最大值没有超过 res，那么不递归
                if (maxs[k] > res) {
                    res = max(res, dfs(i, j, k, false, 2 - target) + 1);
                }
            }
            return res;
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                int maxs[4] = {m - i, j + 1, i + 1, n - j}; // 理论最大值（走到底）
                for (int k = 0; k < 4; k++) { // 枚举起始方向
                    // 优化一：如果理论最大值没有超过 ans，那么不递归
                    if (maxs[k] > ans) {
                        ans = max(ans, dfs(i, j, k, true, 2) + 1);
                    }
                }
            }
        }
        return ans;
    }
};
