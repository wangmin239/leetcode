/* Original Solution 1 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size = 9;

        auto checkRow = [&](int row) {
            vector<int> digits(size + 1, 0);

            for (int col = 0; col < size; col++) {
                char ch = board[row][col];

                if (isdigit(ch) == false) {
                    continue;
                }
                int index = static_cast<int>(ch - '0');
                if (digits[index] != 0) {
                    return false;
                }
                ++digits[index];
            }

            return true;
        };

        auto checkCol = [&](int col) {
            vector<int> digits(size + 1, 0);

            for (int row = 0; row < size; row++) {
                char ch = board[row][col];

                if (isdigit(ch) == false) {
                    continue;
                }
                int index = static_cast<int>(ch - '0');
                if (digits[index] != 0) {
                    return false;
                }
                ++digits[index];
            }

            return true;
        };

        auto checkMatrix = [&](int x, int y) {
            vector<int> digits(size + 1, 0);
            const int len = 3;

            for (int row = x; row < x + len; row++) {
                for (int col = y; col < y + len; col++) {
                    char ch = board[row][col];

                    if (isdigit(ch) == false) {
                        continue;
                    }
                    int index = static_cast<int>(ch - '0');
                    if (digits[index] != 0) {
                        return false;
                    }
                    ++digits[index];
                }
            }

            return true;
        };

        for (int id = 0; id < size; id++) {
            if (checkRow(id) == false || checkCol(id) == false) {
                return false;
            }
        }

        const int step = 3;
        for (int row = 0; row < size; row += step) {
            for (int col = 0; col < size; col += step) {
                if (checkMatrix(row, col) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int columns[9][9];
        int subboxes[3][3][9];
        
        memset(rows,0,sizeof(rows));
        memset(columns,0,sizeof(columns));
        memset(subboxes,0,sizeof(subboxes));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i / 3][j / 3][index]++;
                    if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
