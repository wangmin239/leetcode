
/* Original Solution 1 */
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int rows = matrix.size();
        int cols = matrix.front().size();
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                ans += matrix[row][col];
                int maxEdge = min(row, col) + 1;
                
                for (int edge = 1; edge < maxEdge; edge++) {
                    int isSquare = 1;
                    for (int i = row - edge; i <= row; i++) {
                        for (int j = col - edge; j <= col; j++) {
                            if (matrix[i][j] == 0) {
                                isSquare = 0;
                                break;
                            }
                        }
                    }
                    
                    ans += isSquare;
                }
            }
        }
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    f[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 0) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]}) + 1;
                }
                ans += f[i][j];
            }
        }
        return ans;
    }
};
