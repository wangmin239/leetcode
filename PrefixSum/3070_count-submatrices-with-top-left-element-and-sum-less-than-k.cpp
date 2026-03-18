/* Original Solution 1 */
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1));
        int cnt = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j] + grid[i][j];
                if (prefixSum[i + 1][j + 1] <= k) {
                    ++cnt;
                } else {
                    break;
                }
            }
        }

        return cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector sum(m + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
                ans += sum[i + 1][j + 1] <= k;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        vector<int> col_sum(n);
        int ans = 0;
        for (auto& row : grid) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                col_sum[j] += row[j];
                s += col_sum[j];
                if (s > k) {
                    break;
                }
                ans++;
            }
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> cols(m);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int rows = 0;
            for (int j = 0; j < m; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
                }
            }
        }
        return res;
    }
};

