/* Original Solution 1 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        /* swap the left half and right half */
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            for (int row = 0; row < n; row++) {
                swap(matrix[row][i], matrix[row][j]);
            }
        }
        
        /* swap the left triangle and right triangle */
        for (int row = 0; row < n - 1; row++) {
            for (int col = 0; col < n - row - 1; col++) {
                swap(matrix[row][col], matrix[n - col - 1][n - row - 1]);
            }
        }

    }
};


/* Official Solution 1 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
