class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isMin = true, isMax = true;
                for (int k = 0; k < n; k++) {
                    if (matrix[i][k] < matrix[i][j]) {
                        isMin = false;
                        break;
                    }
                }
                if (!isMin) {
                    continue;
                }
                for (int k = 0; k < m; k++) {
                    if (matrix[k][j] > matrix[i][j]) {
                        isMax = false;
                        break;
                    }
                }
                if (isMax) {
                    ret.push_back(matrix[i][j]);
                }
            }
        }
        return ret;
    }
};



class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> minRow(m, INT_MAX), maxCol(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }
        vector<int> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    ret.push_back(matrix[i][j]);
                }
            }
        }
        return ret;
    }
};





class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        vector<int> ans;

        for (int row = 0; row < rows; row++) {
            int maxCol;
            int luckyNum = INT_MAX;
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] < luckyNum) {
                    luckyNum = matrix[row][col];
                    maxCol = col;
                }
            }
            
            bool findLuckyNum = true;
            for (int i = 0; i < rows; i++) {
                if (luckyNum < matrix[i][maxCol]) {
                    findLuckyNum = false;
                    break;
                }
            }
            
            if (findLuckyNum == true) {
                ans.push_back(luckyNum);
                break
            }
        }
        
        return ans;
    }
};



class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        vector<int> ans;

        for (int row = 0; row < rows; row++) {
            int maxCol;
            int luckyNum = INT_MAX;
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] < luckyNum) {
                    luckyNum = matrix[row][col];
                    maxCol = col;
                }
            }
            
            bool findLuckyNum = true;
            for (int i = 0; i < rows; i++) {
                if (luckyNum < matrix[i][maxCol]) {
                    findLuckyNum = false;
                    break;
                }
            }
            
            if (findLuckyNum == true) {
                ans.push_back(luckyNum);
            }
        }
        
        return ans;
    }
};