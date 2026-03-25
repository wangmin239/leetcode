/* Original Solution 1 */
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        long long topSum = 0LL;
        long long sum = 0LL;
        vector<long long> rowSum(rows);


        for (int x = 0; x < rows; x++) {
            sum += accumulate(grid[x].begin(), grid[x].end(), 0LL);
            rowSum[x] = sum;
        }

        if (sum & 0x1) {
            return false;
        }

        long long halfSum = sum / 2;
        for (int x = 0; x < rows; x++) {
            if (rowSum[x] == halfSum) {
                return true;
            }
        }

        auto colSum = [&grid, rows](int col) {
            long long sum = 0LL;
            for (int row = 0; row < rows; row++) {
                sum += grid[row][col];
            }
            return sum;
        };


        for (int y = 0; y < cols; y++ ) {
            halfSum -= colSum(y);
            if (halfSum == 0) {
                return true;
            } else if (halfSum < 0) {
                break;
            }
        }

        return false;
    }
};

/* Original Solution 2 */
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector<vector<long long>> prefixSum(rows + 1, vector<long long>(cols + 1, 0LL));
        long long sum = 0LL;

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                prefixSum[x + 1][y + 1] = prefixSum[x][y + 1] + prefixSum[x + 1][y] - prefixSum[x][y] + grid[x][y];
                sum += grid[x][y];
            }
        }

        if ((sum & 0x1) == 0x1) {
            return false;
        }

        sum /= 2;

        for (int x = 0; x < rows; x++) {
            if (prefixSum[x + 1][cols] == sum) {
                return true;
            }
        }

        for (int y = 0; y < cols; y++) {
            if (prefixSum[rows][y] == sum) {
                return true;
            }
        }

        return false;

    }
};


/* Official Solution 1 */
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long sum[m + 1][n + 1];
        long long total = 0;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
                total += grid[i][j];
            }
        }
        for (int i = 0; i < m - 1; i++) {
            if (total == sum[i + 1][n] * 2) {
                return true;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (total == sum[m][i + 1] * 2) {
                return true;
            }
        }
        return false;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        long long sum;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 2; k++) {
            sum = 0;
            m = grid.size();
            n = grid[0].size();
            for (int i = 0; i < m - 1; i++) {
                for(int j = 0; j < n; j++){
                    sum += grid[i][j];
                }
                if(sum * 2 == total){
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};
