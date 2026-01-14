
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(4, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < (m + 1) / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int ones = grid[i][j], cnt = 1;
                if (j != n - 1 - j) {
                    ones += grid[i][n - 1 - j];
                    cnt++;
                }
                if (i != m - 1 - i) {
                    ones += grid[m - 1 - i][j];
                    cnt++;
                }
                if (i != m - 1 - i && j != n - 1 - j) {
                    ones += grid[m - 1 - i][n - 1 - j];
                    cnt++;
                }
                // 将这一组全部变成 1 的代价
                int cnt1 = cnt - ones;
                // 将这一组全部变成 0 的代价
                int cnt0 = ones;
                vector<int> tmp(4);
                for (int k = 0; k < 4; k++) {
                    tmp[k] = f[k] + cnt0;
                }
                for (int k = 0; k < 4; k++) {
                    tmp[(k + cnt) % 4] = min(tmp[(k + cnt) % 4], f[k] + cnt1);
                }
                swap(f, tmp);
            }
        }
        return f[0];
    }
};



class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int cnt1 = grid[i][j] + grid[i][n - 1 - j] +
                           grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                ans += min(cnt1, 4 - cnt1);
            }
        }

        int diff = 0, cnt1 = 0;
        if (m & 1) {
            for (int j = 0; j < n / 2; j++) {
                if (grid[m / 2][j] ^ grid[m / 2][n - 1 - j]) {
                    diff++;
                } else {
                    cnt1 += grid[m / 2][j] * 2;
                }
            }
        }
        if (n & 1) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] ^ grid[m - 1 - i][n / 2]) {
                    diff++;
                } else {
                    cnt1 += grid[i][n / 2] * 2;
                }
            }
        }
        if (m & 1 && n & 1) {
            ans += grid[m / 2][n / 2];
        }
        if (diff > 0) {
            ans += diff;
        } else {
            ans += cnt1 % 4;
        }
        return ans;
    }
};



class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        int totalFlips = 0;
        
        auto getMinFlips = [](int leftUp, int leftDown, int rightUp, int rightDown) {
                int bitsCnt[2] = {0, 0};
                
                ++bitsCnt[leftUp];
                ++bitsCnt[leftDown];
                ++bitsCnt[rightUp];
                ++bitsCnt[rightDown];
                
                return min(bitsCnt[0], bitsCnt[1]);
        };
        
        /* Calculate the total flips according to every row */
        for (int bottom = 0, top = rows - 1; bottom < top; bottom++, top--) {
            for (int left = 0, right = cols - 1; left < right; left++, right--) {
                totalFlips +=  getMinFlips(grid[bottom][left], grid[top][left], grid[bottom][right], grid[top][right]);
            }
        }
        
        int flips = 0;
        int oneCnt = 0;
        if (cols & 0x1) {
            int col = cols / 2;
            for (int bottom = 0, top = rows - 1; bottom < top; bottom++, top--) {
                flips += grid[bottom][col] ^ grid[top][col];
                oneCnt += grid[bottom][col] + grid[top][col];
            }
        }
        
        if (rows & 0x1) {
            int row = rows / 2;
            for (int left = 0, right = cols - 1; left < right; left++, right--) {
                flips += grid[row][left] ^ grid[row][right];
                oneCnt += grid[row][left] + grid[row][right];
            }            
        }
        
        
        if (rows % 2 == 1 && cols % 2 == 1) {
            totalFlips += grid[rows / 2][cols / 2];
        }
        
        return totalFlips + (flips > 0 ? flips : oneCnt % 4);
    }
};
