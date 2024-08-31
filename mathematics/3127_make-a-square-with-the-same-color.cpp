class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                if (check(grid, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char>> &grid, int x, int y) {
        int count = 0;
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                count += (grid[x + i][y + j] == 'B');
            }
        }
        return count != 2;
    }
};


class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int bCnt = 0;
        
        auto block = [&](int x, int y) {
            int wCnt = 0;
            
            for (int row = 0; row < 2; row++) {
                for (int col = 0; col < 2; col++) {
                    if (grid[x + row][y + col] == 'W') {
                        ++wCnt;
                    }
                }
            }
            
            return wCnt != 2;
        };
        
        return block(0, 0) || block(0, 1) || block(1, 0) || block(1, 1);
    }
};