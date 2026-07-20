/* Original Solution 1 */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector<int> lastCol(rows);

        auto oper = [&]() {
            for (int i = 0; i < rows; i++) {
                lastCol[i] = grid[i][cols - 1];
            }

            for (int j = cols - 1; j > 0; j--) {
                for (int i = 0; i < rows; i++) {
                    grid[i][j] = grid[i][j - 1];
                }
            }

            for (int i = 0; i < rows - 1; i++) {
                grid[i + 1][0] = lastCol[i];
            }

            grid[0][0] = lastCol.back();
        };


        while (k--) {
            oper();
        }

        return grid;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index1 = (i * n + j + k) % (m * n);
                ret[index1 / n][index1 % n] = grid[i][j];
            }
        }
        return ret;
    }
};
