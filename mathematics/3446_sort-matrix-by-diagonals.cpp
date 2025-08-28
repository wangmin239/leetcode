/* Original Solution 1 */
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> matrix(n, vector<int>(n));
        
        /* left diagonal */
        for (int col = 1; col < n; col++) {
            auto& tmp = matrix.front();
            for (int row = 0; row < n - col; row++) {
                tmp[row + col] = grid[row][col + row];
            }
            sort(tmp.begin() + col, tmp.end(), less<int>());
            for (int row = 0; row < n - col; row++) {
                matrix[row][col + row] = tmp[row + col];
            }
        }
        
        /* right diagonal */
        for (int  row = 0; row < n; row++) {
            auto& tmp = matrix.back();
            for (int col = 0; col < n - row; col++) {
                tmp[col] = grid[row + col][col];
            }
            sort(tmp.begin(), tmp.end() - row, greater<int>());
            for (int col = 0; col < n - row; col++) {
                matrix[row + col][col] = tmp[col];
            }
        }
        
        return matrix;
    }
};



/* Original Solution 2 */
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        /* left diagonal */
        for (int col = 1; col < n; col++) {
            vector<int> tmp;
            for (int row = 0; row < n - col; row++) {
                tmp.push_back(grid[row][col + row]);
            }
            sort(tmp.begin(), tmp.end(), less<int>());
            for (int row = 0; row < n - col; row++) {
                grid[row][col + row] = tmp[row];
            }
        }
        
        /* right diagonal */
        for (int  row = 0; row < n; row++) {
            vector<int> tmp;
            for (int col = 0; col < n - row; col++) {
                tmp.push_back(grid[row + col][col]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            for (int col = 0; col < n - row; col++) {
                grid[row + col][col] = tmp[col];
            }
        }
        
        return grid;
    }
};



/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; i + j < n; j++) {
                tmp.push_back(grid[i + j][j]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp[j];
            }
        }
        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; j + i < n; i++) {
                tmp.push_back(grid[i][j + i]);
            }
            sort(tmp.begin(), tmp.end());
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];
            }
        }
        return grid;
    }
};