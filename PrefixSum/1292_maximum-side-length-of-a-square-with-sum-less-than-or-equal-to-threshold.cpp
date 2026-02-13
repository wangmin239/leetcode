
/* Original Solution 1 */
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat.front().size();
        int upLimit = min(rows, cols);
        vector<vector<int>> preSum(rows, vector<int>(cols + 1, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
               preSum[row][col + 1] = preSum[row][col] + mat[row][col];
            }
        }

        auto isSquare = [&preSum, &threshold](int x, int y, int k) {
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += preSum[x + i][y + k] - preSum[x + i][y];
            }

            return sum <= threshold;

        };

        int width = upLimit + 1;
        while (--width) {
            for (int row = 0; row <= rows - width; row++) {
                for (int col = 0; col <= cols - width; col++) {
                    if (isSquare(row, col, width) == true) {
                        return width;
                    }
                }
            }
        }

        return width;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat.front().size();
        int upLimit = min(rows, cols);
        vector<vector<int>> preSum(rows + 1, vector<int>(cols + 1, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
               preSum[row + 1][col + 1] = preSum[row + 1][col] + preSum[row][col + 1] + mat[row][col] - preSum[row][col];
            }
        }

        auto isSquare = [&preSum, &threshold](int x, int y, int k) {
            int sum = preSum[x + k][y + k] - preSum[x + k][y] - preSum[x][y + k];
            sum += preSum[x][y];
            return sum <= threshold;

        };

        int width = upLimit + 1;
        while (--width) {
            for (int row = 0; row <= rows - width; row++) {
                for (int col = 0; col <= cols - width; col++) {
                    if (isSquare(row, col, width) == true) {
                        return width;
                    }
                }
            }
        }

        return width;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int l = 1, r = min(m, n), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool find = false;
            for (int i = 1; i <= m - mid + 1; ++i) {
                for (int j = 1; j <= n - mid + 1; ++j) {
                    if (getRect(P, i, j, i + mid - 1, j + mid - 1) <= threshold) {
                        find = true;
                    }
                }
            }
            if (find) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int r = min(m, n), ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int c = ans + 1; c <= r; ++c) {
                    if (i + c - 1 <= m && j + c - 1 <= n && getRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
                        ++ans;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
            }
        }

        // 返回左上角在 (r1, c1)，右下角在 (r2, c2) 的子矩阵元素和
        auto query = [&](int r1, int c1, int r2, int c2) -> int {
            return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 边长为 ans+1 的正方形，左上角在 (i, j)，右下角在 (i+ans, j+ans)
                while (i + ans < m && j + ans < n && query(i, j, i + ans, j + ans) <= threshold) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
