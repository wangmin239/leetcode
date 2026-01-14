/* Original Solution */
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();    
        vector<vector<int>> matrix(rows, vector<int>(cols));
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                unordered_set<int> top, bottom;
                /* bottom diagonal */
                for (int i = 1, j = 1; row + i < rows && col + j < cols; i++, j++) {
                    bottom.insert(grid[row + i][col + j]);
                }
                /* top diagonal */
                for (int i = 1, j = 1; row - i >= 0 && col - j >= 0; i++, j++) {
                    top.insert(grid[row - i][col - j]);
                }
                matrix[row][col] = abs(static_cast<int>(top.size()) - static_cast<int>(bottom.size()));
            }
        }
        
        return matrix;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            int x = i, y = 0;
            set<int> s;
            while (x < m && y < n) {
                res[x][y] += s.size();
                s.insert(grid[x][y]);
                x += 1;
                y += 1;
            }
        }

        for (int j = 1; j < n; ++j) {
            int x = 0, y = j;
            set<int> s;
            while (x < m && y < n) {
                res[x][y] += s.size();
                s.insert(grid[x][y]);
                x += 1;
                y += 1;
            }
        }

        for (int i = 0; i < m; ++i) {
            int x = i, y = n - 1;
            set<int> s;
            while (x >= 0 && y >= 0) {
                res[x][y] -= s.size();
                res[x][y] = abs(res[x][y]);
                s.insert(grid[x][y]);
                x -= 1;
                y -= 1;
            }
        }

        for (int j = n - 2; j >= 0; --j) {
            int x = m - 1, y = j;
            set<int> s;
            while (x >= 0 && y >= 0) {
                res[x][y] -= s.size();
                res[x][y] = abs(res[x][y]);
                s.insert(grid[x][y]);
                x -= 1;
                y -= 1;
            }
        }

        return res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                set<int> s1;
                int x = i + 1, y = j + 1;
                while (x < m && y < n) {
                    s1.insert(grid[x][y]);
                    x += 1;
                    y += 1;
                }
                set<int> s2;
                x = i - 1, y = j - 1;
                while (x >= 0 && y >= 0) {
                    s2.insert(grid[x][y]);
                    x -= 1;
                    y -= 1;
                }
                res[i][j] = abs((int)s1.size() - (int)s2.size());
            }
        }
        return res;
    }
};
