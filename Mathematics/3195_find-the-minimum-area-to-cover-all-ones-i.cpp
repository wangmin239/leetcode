/* Original Solution 1 */
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        
        auto getStart = [&] (int& start) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    if (grid[row][col] != 0) {
                        start = row;
                        return;
                    }
                }
            }
        };

        auto getEnd = [&] (int& end) {
            for (int row = rows - 1; row >= 0; row--) {
                for (int col = 0; col < cols; col++) {
                    if (grid[row][col] != 0) {
                        end = row;
                        return;
                    }
                }
            }
        };        
        
        auto getLeft = [&] (int& left) {
            for (int col = 0; col < cols; col++) {
                for (int row = 0; row < rows; row++) {
                    if (grid[row][col] != 0) {
                        left = col;
                        return;
                    }
                }
            }
        };

        auto getRight = [&] (int& right) {
            for (int col = cols - 1; col >= 0; col--) {
                for (int row = 0; row < rows; row++) {
                    if (grid[row][col] != 0) {
                        right = col;
                        return;
                    }
                }
            }
        };
        
        int startRow = 0, endRow = 0;
        int leftCol = 0, rightCol = 0;
        
        getStart(startRow);
        getEnd(endRow);
        getLeft(leftCol);
        getRight(rightCol);
        
        if (startRow == 0 && endRow == 0 && leftCol == 0 && right == 0) {
            return grid[0][0];
        }
        return (endRow - startRow + 1) * (rightCol - leftCol + 1);
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int min_i = n, max_i = 0;
        int min_j = m, max_j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};
