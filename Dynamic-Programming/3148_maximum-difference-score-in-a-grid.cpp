class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> precol(n, INT_MIN);
        int ans = INT_MIN;
        for (int i = 0; i < m; ++i) {
            int prerow = INT_MIN;
            for (int j = 0; j < n; ++j) {
                int f = INT_MIN;
                if (i > 0) {
                    f = max(f, grid[i][j] + precol[j]);
                }
                if (j > 0) {
                    f = max(f, grid[i][j] + prerow);
                }
                ans = max(ans, f);
                precol[j] = max(precol[j], max(f, 0) - grid[i][j]);
                prerow = max(prerow, max(f, 0) - grid[i][j]);
            }
        }
        return ans;
    }
};



class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prerow(m, vector<int>(n));
        vector<vector<int>> precol(m, vector<int>(n));
        vector<vector<int>> f(m, vector<int>(n, INT_MIN));
        int ans = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    f[i][j] = max(f[i][j], grid[i][j] + precol[i - 1][j]);
                }
                if (j > 0) {
                    f[i][j] = max(f[i][j], grid[i][j] + prerow[i][j - 1]);
                }
                ans = max(ans, f[i][j]);
                prerow[i][j] = precol[i][j] = max(f[i][j], 0) - grid[i][j];
                if (i > 0) {
                    precol[i][j] = max(precol[i][j], precol[i - 1][j]);
                }
                if (j > 0) {
                    prerow[i][j] = max(prerow[i][j], prerow[i][j - 1]);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> premin(m, vector<int>(n, INT_MAX));
        int ans = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int pre = INT_MAX;
                if (i > 0) {
                    pre = min(pre, premin[i - 1][j]);
                }
                if (j > 0) {
                    pre = min(pre, premin[i][j - 1]);
                }
                // i = j = 0 时没有转移
                if (i + j > 0) {
                    ans = max(ans, grid[i][j] - pre);
                }
                premin[i][j] = min(pre, grid[i][j]);
            }
        }
        return ans;
    }
};
