/* Official Solution 1 */
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        auto rightRotation = [n](vector<vector<int>>& grid) {
            vector<vector<int>> rotateMatrix(n, vector<int>(n));
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    rotateMatrix[col][n - row -1] = grid[row][col];
                }
            }
            grid = rotateMatrix;
        };
        const int maxRotationCnt = 4;

        for (int cnt = 0; cnt < maxRotationCnt; cnt++) {
            if (mat == target) {
                return true;
            }
            rightRotation(mat);
        }

        return mat == target;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int temp;
    bool flag;

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        // 最多旋转 4 次
        for (int k = 0; k < 4; ++k) {
            // 旋转操作
            for (int i = 0; i < n / 2; ++i) {
                for (int j = 0; j < (n + 1) / 2; ++j) {
                    temp = mat[i][j];
                    mat[i][j] = mat[n-1-j][i];
                    mat[n-1-j][i] = mat[n-1-i][n-1-j];
                    mat[n-1-i][n-1-j] = mat[j][n-1-i];
                    mat[j][n-1-i] = temp;
                }
            }
            
            if (mat == target) {
                return true;
            }
        }
        return false;    
    }
};



/* Official Solution 2 */
class Solution {
    // 48. 旋转图像
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // 遍历对角线上方元素，做转置
                swap(matrix[i][j], matrix[j][i]);
            }
            ranges::reverse(matrix[i]); // 行翻转
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) {
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};
