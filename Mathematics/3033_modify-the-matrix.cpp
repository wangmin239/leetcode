class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int j = 0; j < m; j++) {
            int zd = -1;
            for (int i = 0; i < n; i++) {
                zd = max(zd, matrix[i][j]);
            }
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = zd;
                }
            }
        }
        return matrix;
    }
};



class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        auto convertMax = [](vector<vector<int>>& matrix, const int rows, const int col) {
                int maxVal = 0;
                unique_ptr<bool[]> isNegtive(new bool [rows] {false});
                bool* ptr = isNegtive.get();
                for (int row = 0; row < rows; row++) {
                    maxVal = max(matrix[row][col], maxVal);
                    if (matrix[row][col] == -1) {
                        ptr[row] = true;
                    }
                }
                
                for (int row = 0; row < rows; row++) {
                    if (ptr[row] == true) {
                        matrix[row][col] = maxVal;
                    }
                }
                return ;
        };

        

        for (int col = 0; col < cols; col++) {
            convertMax(matrix, rows, col);
        }
        
        return matrix;
    }
};




class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix);
        int rows = matrix.size();
        int cols = matrix.front().size();
        auto getMaxCols = [](const vector<vector<int>>& matrix, const int rows, const int col) {
                int maxVal = 0;
                for (int row = 0; row < rows; row++) {
                    maxVal = max(matrix[row][col], maxVal);
                }
                return maxVal;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] ==  -1) {
                    ans[i][j] = getMaxCols(matrix, rows, j);
                }
            }
        }
        
        return ans;
    }
};