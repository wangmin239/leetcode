/* Original Solution 1 */
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        int circle = min(rows, cols) / 2;
        int girth = (rows + cols) * 2 - 4;
        vector<int> row(girth, 0);
        
        for (int x = 0; x < circle; x++) {
            int offset = k % girth;
            int j = 0;
            /* top side */
            for (int i = x; i < cols - x; i++) {
                row[j++] = grid[x][i];
            }
            /* right side */
            for (int i = x + 1; i < rows - x; i++) {
                row[j++] = grid[i][cols - x - 1];
            }
            
            /* bottom side */
            for (int i = cols - x - 2; i > x; i--) {
                row[j++] = grid[rows - x - 1][i];
            }
            
            /* left side*/
            for (int i = rows - x - 1; i > x; i--) {
                row[j++] = grid[i][x];
            }
            
            j = 0;
            /* assign top side */
            for (int i = x; i < cols - x; i++, j++) {
                grid[x][i] = row[(j + offset) % girth];
            }
            /* right side */
            for (int i = x + 1; i < rows - x; i++, j++) {
                grid[i][cols - x - 1] = row[(j + offset) % girth];
            }
            
            /* bottom side */
            for (int i = cols - x - 2; i > x; i--, j++) {
                grid[rows - x - 1][i] = row[(j + offset) % girth];
            }
            
            /* left side*/
            for (int i = rows - x - 1; i > x; i--, j++) {
                grid[i][x] = row[(j + offset) % girth];
            }            
            girth -= 8;
        }
        
        return grid;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int nlayer = min(m / 2, n / 2);   // 层数
        // 从左上角起逆时针枚举每一层
        for (int layer = 0; layer < nlayer; ++layer){
            vector<int> r, c, val;   // 每个元素的行下标，列下标与数值
            for (int i = layer; i < m - layer - 1; ++i){   // 左
                r.push_back(i);
                c.push_back(layer);
                val.push_back(grid[i][layer]);
            }
            for (int j = layer; j < n - layer - 1; ++j){   // 下
                r.push_back(m - layer - 1);
                c.push_back(j);
                val.push_back(grid[m-layer-1][j]);
            }
            for (int i = m - layer - 1; i > layer; --i){   // 右
                r.push_back(i);
                c.push_back(n - layer - 1);
                val.push_back(grid[i][n-layer-1]);
            }
            for (int j = n - layer - 1; j > layer; --j){   // 上
                r.push_back(layer);
                c.push_back(j);
                val.push_back(grid[layer][j]);
            }
            int total = val.size();   // 每一层的元素总数
            int kk = k % total;   // 等效轮转次数
            // 找到每个下标对应的轮转后的取值
            for (int i = 0; i < total; ++i){
                int idx = (i + total - kk) % total;   // 轮转后取值对应的下标
                grid[r[i]][c[i]] = val[idx];
            }
        }
        return grid;
    }
};


/* Official Solution 2 */
class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m0 = grid.size(), n0 = grid[0].size();
        vector<int> a;
        a.reserve((m0 + n0 - 2) * 2); // 预分配空间

        // 从外到内枚举圈
        for (int i = 0; i < min(m0, n0) / 2; i++) {
            int m = m0 - i * 2, n = n0 - i * 2; // 这一圈的行数和列数
            int x = i, y = i; // 这一圈的左上角
            a.resize(0);
            for (auto& [dx, dy] : DIRS) {
                for (int t = 0; t < n - 1; t++) {
                    a.push_back(grid[x][y]);
                    x += dx;
                    y += dy;
                }
                swap(m, n); // 见 54. 螺旋矩阵 我的题解
            }

            int shift = k % a.size();
            ranges::rotate(a, a.begin() + shift);

            // 注意此时 (x, y) 又回到了左上角
            int j = 0;
            for (auto& [dx, dy] : DIRS) {
                for (int t = 0; t < n - 1; t++) {
                    grid[x][y] = a[j++];
                    x += dx;
                    y += dy;
                }
                swap(m, n);
            }
        }

        return grid;
    }
};
