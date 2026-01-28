/* Official Solution 1 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(), [&](const auto& p1, const auto& p2) -> bool {
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        });
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i++) {
                minCost = min(minCost, costs[points[i].first][points[i].second]);
                if (i + 1 < points.size() && grid[points[i].first][points[i].second] == grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int mx = 0;
        for (auto& row : grid) {
            mx = max(mx, ranges::max(row));
        }

        vector<int> suf_min_f(mx + 2, INT_MAX);
        vector<int> min_f(mx + 1);
        vector<int> f(n + 1);

        for (int t = 0; t <= k; t++) {
            ranges::fill(min_f, INT_MAX);

            // 64. 最小路径和（空间优化写法）
            ranges::fill(f, INT_MAX / 2);
            f[1] = -grid[0][0]; // 起点的成本不算
            for (auto& row : grid) {
                for (int j = 0; j < n; j++) {
                    int x = row[j];
                    f[j + 1] = min(min(f[j], f[j + 1]) + x, suf_min_f[x]);
                    min_f[x] = min(min_f[x], f[j + 1]);
                }
            }

            // 计算 min_f 的后缀最小值
            for (int i = mx; i >= 0; i--) {
                suf_min_f[i] = min(suf_min_f[i + 1], min_f[i]);
            }
        }

        return f[n];
    }
};


/* Official Solution 3 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k && grid[0][0] >= grid[m - 1][n - 1]) {
            return 0;
        }

        int mx = 0;
        for (auto& row : grid) {
            mx = max(mx, ranges::max(row));
        }

        vector<int> suf_min_f(mx + 2, INT_MAX);
        vector<int> min_f(mx + 1);
        vector<int> f(n + 1);

        for (int t = 0; t <= k; t++) {
            ranges::fill(min_f, INT_MAX);

            // 64. 最小路径和（空间优化写法）
            ranges::fill(f, INT_MAX / 2);
            f[1] = -grid[0][0]; // 起点的成本不算
            for (auto& row : grid) {
                for (int j = 0; j < n; j++) {
                    int x = row[j];
                    f[j + 1] = min(min(f[j], f[j + 1]) + x, suf_min_f[x]);
                    min_f[x] = min(min_f[x], f[j + 1]);
                }
            }

            auto tmp = suf_min_f;
            // 计算 min_f 的后缀最小值
            for (int i = mx; i >= 0; i--) {
                suf_min_f[i] = min(suf_min_f[i + 1], min_f[i]);
            }
            if (suf_min_f == tmp) {
                // 收敛了：传送不改变 suf_min_f，那么无论再传送多少次都不会改变 suf_min_f
                break;
            }
        }

        return f[n];
    }
};
