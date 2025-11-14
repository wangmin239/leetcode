/* Original Solution 1 */
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        for (const auto& query : queries) {
            int startRow = query[0];
            int endRow = query[2] + 1;
            int startCol = query[1];
            int endCol = query[3] + 1;
            /* Marks the starting and ending points */
            for (int row = startRow; row < endRow; row++) {
                ++matrix[row][startCol];
                if (endCol < n) {
                    --matrix[row][endCol];
                }
            }
        }
        /* replenish the matrix with correct values */
        for (int row = 0; row < n; row++) {
            for (int col = 1; col < n; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }
        
        return matrix;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // 二维差分
        vector diff(n + 2, vector<int>(n + 2));
        for (auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1 + 1][c1 + 1]++;
            diff[r1 + 1][c2 + 2]--;
            diff[r2 + 2][c1 + 1]--;
            diff[r2 + 2][c2 + 2]++;
        }

        // 原地计算 diff 的二维前缀和，然后填入答案
        vector ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diff[i + 1][j + 1] += diff[i + 1][j] + diff[i][j + 1] - diff[i][j];
                ans[i][j] = diff[i + 1][j + 1];
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector diff(n + 1, vector<int>(n + 1));
        for (const auto& query : queries) {
            int row1 = query[0], col1 = query[1];
            int row2 = query[2], col2 = query[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }
        vector mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i - 1][j];
                int x2 = (j == 0) ? 0 : mat[i][j - 1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
};
