class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rowCnt = 0, colCnt = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j1 = 0, j2 = n - 1; j1 < j2; j1++, j2--) {
                if (grid[i][j1] ^ grid[i][j2]) {
                    rowCnt++;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i1 = 0, i2 = m - 1; i1 < i2; i1++, i2--) {
                if (grid[i1][j] ^ grid[i2][j]) {
                    colCnt++;
                }
            }
        }
        return min(colCnt, rowCnt);
    }
};



class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        
        int rowFlipCnt = 0;
        auto checkRow = [&grid](int row, int cols) {
            int cnt = 0;
            for (int left = 0, right = cols - 1; left < right; left++, right--) {
                if (grid[row][left] != grid[row][right]) {
                    ++cnt;
                }
            }
            return cnt;
        };
        
        for (int row = 0; row < rows; row++) {
            rowFlipCnt += checkRow(row, cols); 
        }
        
        int colFlipCnt = 0;
        auto checkCol = [&grid](int rows, int col) {
            int cnt = 0;
            for (int start = 0, end = rows - 1; start < end; ++start, --end) {
                if (grid[start][col] != grid[end][col]) {
                    ++cnt;
                }
            }
            return cnt;
        };
        
        for (int col = 0; col < cols; col++) {
            colFlipCnt += checkCol(rows, col);
        }
        return min(colFlipCnt, rowFlipCnt);
    }
};