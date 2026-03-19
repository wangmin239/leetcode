/* Original Solution 1 */
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector<int> xCols(cols, 0);
        vector<int> yCols(cols, 0);
        int cnt = 0;

        for (int i = 0; i < rows; i++) {
            int sumX = 0;
            int sumY = 0;
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'X') {
                    ++xCols[j];
                } else if (grid[i][j] == 'Y') {
                    ++yCols[j];
                }
                sumX += xCols[j];
                sumY += yCols[j];

                if (sumX > 0 && sumX == sumY) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<array<int, 2>>> sum(m + 1, vector<array<int, 2>>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] + sum[i][j + 1][1] - sum[i][j][1];
                if (grid[i][j] != '.') {
                    sum[i + 1][j + 1][grid[i][j] & 1]++;
                }
                if (sum[i + 1][j + 1][0] && sum[i + 1][j + 1][0] == sum[i + 1][j + 1][1]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        vector<array<int, 2>> col_cnt(grid[0].size());
        for (auto& row : grid) {
            int s0 = 0, s1 = 0;
            for (int j = 0; j < row.size(); j++) {
                if (row[j] != '.') {
                    col_cnt[j][row[j] & 1]++;
                }
                s0 += col_cnt[j][0];
                s1 += col_cnt[j][1];
                if (s0 && s0 == s1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<array<int, 2>>> sum(n + 1, vector<array<int, 2>>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                    sum[i + 1][j + 1][1] = 1;
                } else if (grid[i][j] == 'Y') {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                } else {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                }
                ans += (!sum[i + 1][j + 1][0] && sum[i + 1][j + 1][1]) ? 1 : 0;
            }
        }
        return ans;
    }
};
