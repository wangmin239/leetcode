/* Original Solution 1 */
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector<vector<int>> diffMatrix(rows - k + 1, vector<int>(cols - k + 1));
        auto getMinAbs = [&grid, k](int row, int col) {
            int size = k * k;
            vector<int> subGrid(size);
            int id = 0;
            int minDiff = INT_MAX;

            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    subGrid[id++] = grid[row + i][col + j];
                }
            }

            sort(subGrid.begin(), subGrid.end());
            for (int i = 1; i < size; i++) {
                if (subGrid[i] != subGrid[i - 1]) {
                    minDiff = min(minDiff, subGrid[i] - subGrid[i - 1]);
                }
            }
            return minDiff == INT_MAX ? 0: minDiff;
        };

        for (int i = 0; i <= rows - k; i++) {
            for (int j = 0; j <= cols - k; j++) {
                diffMatrix[i][j] = getMinAbs(i, j);
            }
        }

        return diffMatrix;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector ans(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> a;
                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        a.push_back(grid[i + x][j + y]);
                    }
                }
                ranges::sort(a);

                int res = INT_MAX;
                for (int p = 1; p < a.size(); p++) {
                    if (a[p] > a[p - 1]) { // 题目要求相减的两个数必须不同
                        res = min(res, a[p] - a[p - 1]);
                    }
                }
                if (res < INT_MAX) {
                    ans[i][j] = res;
                }
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                vector<int> kgrid;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kgrid.push_back(grid[x][y]);
                    }
                }
                int kmin = INT_MAX;
                sort(kgrid.begin(), kgrid.end());
                for (int t = 1; t < kgrid.size(); t++) {
                    if (kgrid[t] == kgrid[t - 1]) {
                        continue;
                    }
                    kmin = min(kmin, kgrid[t] - kgrid[t - 1]);
                }
                if (kmin != INT_MAX) {
                    res[i][j] = kmin;
                }
            }
        }
        return res;
    }
};
