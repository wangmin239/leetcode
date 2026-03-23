/* Original Solution 1 */
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        const int mod = 1e9 + 7;
        vector<vector<long long>> preMul(cols);

        preMul[0].push_back(grid[0][0]);
        for (int i = 1; i < cols; i++) {
            preMul[i].push_back(preMul[i - 1].back() * grid[0][i]);
        }

        for (int x = 1; x < rows; x++) {
            vector<vector<long long>> curMul(cols);
            curMul[0].push_back(preMul[0].back() * grid[x][0]);
            for (int y = 1; y < cols; y++) {
                for (auto ele : preMul[y]) {
                    curMul[y].push_back(ele * grid[x][y]);
                }

                for (auto ele : curMul[y - 1]) {
                    curMul[y].push_back(ele * grid[x][y]);
                }
            }
            preMul = move(curMul);
        }

        auto maxVal = *max_element(preMul[cols -1].begin(), preMul[cols - 1].end());
        if (maxVal < 0LL) {
            return -1;
        }

        return maxVal % mod;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int mod = 1000000000 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> maxgt(m, vector<long long>(n));
        vector<vector<long long>> minlt(m, vector<long long>(n));

        maxgt[0][0] = minlt[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    maxgt[i][j] = max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                    minlt[i][j] = min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                } else {
                    maxgt[i][j] = min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                    minlt[i][j] = max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                }
            }
        }
        if (maxgt[m - 1][n - 1] < 0) {
            return -1;
        } else {
            return maxgt[m - 1][n - 1] % mod;
        }
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> f_min(n), f_max(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long x = grid[i][j];
                if (i == 0 && j == 0) {
                    f_min[0] = f_max[0] = x;
                    continue;
                }

                long long res_min = LLONG_MAX;
                long long res_max = LLONG_MIN;
                if (i > 0) {
                    long long mn = f_min[j], mx = f_max[j];
                    res_min = min(mn * x, mx * x);
                    res_max = max(mn * x, mx * x);
                }
                if (j > 0) {
                    long long mn = f_min[j - 1], mx = f_max[j - 1];
                    res_min = min(res_min, min(mn * x, mx * x));
                    res_max = max(res_max, max(mn * x, mx * x));
                }

                f_min[j] = res_min;
                f_max[j] = res_max;
            }
        }

        long long ans = f_max[n - 1];
        return ans < 0 ? -1 : ans % 1'000'000'007;
    }
};
