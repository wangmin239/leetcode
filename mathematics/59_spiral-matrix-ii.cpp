/* Official Solution */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                matrix[top][column] = num;
                num++;
            }
            for (int row = top + 1; row <= bottom; row++) {
                matrix[row][right] = num;
                num++;
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    matrix[bottom][column] = num;
                    num++;
                }
                for (int row = bottom; row > top; row--) {
                    matrix[row][left] = num;
                    num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
};





/* Official Solution */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int maxNum = n * n;
        int curNum = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int row = 0, column = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
        int directionIndex = 0;
        while (curNum <= maxNum) {
            matrix[row][column] = curNum;
            curNum++;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
                directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
            }
            row = row + directions[directionIndex][0];
            column = column + directions[directionIndex][1];
        }
        return matrix;
    }
};



/* Original Solution */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int i = 1;

        for (int row = 0; row < (n + 1)/ 2; row++) {
            /* top row */
            for (int col = row; col < (n - row); col++) {
                matrix[row][col] = i++;
            }
            
            /* right column */
            for (int rRow = row + 1; rRow < (n - row); rRow++) {
                matrix[rRow][n - row - 1] = i++;
            }
            
            /* bottom row */
            for (int col = n - row - 2; col > row; col--) {
                matrix[n - row - 1][col] = i++;
            }
            
            /* left column */
            for (int lRow = n - row - 1; lRow > row; lRow--) {
                matrix[lRow][row] = i++;
            }
        }
        
        return matrix;
    }
};


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int i = 1;

        for (int row = 0; row < (n + 1)/ 2; row++) {
            /* top row */
            for (int col = row; col < (n - row); col++) {
                matrix[row][col] = i++;
            }
            
            /* right column */
            for (int rRow = row + 1; rRow < (n - row); rRow++) {
                matrix[rRow][n - row - 1] = i++;
            }
            
            /* bottom row */
            for (int col = n - row - 2; col >= row; col--) {
                matrix[n - row - 1][col] = i++;
            }
            
            /* left column */
            for (int lRow = n - row - 2; lRow > row; lRow--) {
                matrix[lRow][row] = i++;
            }
        }
        
        return matrix;
    }
};