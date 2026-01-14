/* Original Solution 1 */
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int guardNum = guards.size();
        int wallNum = walls.size();
        vector<vector<int>> grid(m, vector<int>(n, 0));


        
        auto fillStatus = [&grid](const vector<vector<int>>& points, int status) {
                for (auto point : points) {
                    int row = point.front();
                    int col = point.back();
                    grid[row][col] = status;
                }
            return;
        };
 #define GUARD 2
#define WALL  -1
#define PROTECT 1       
        fillStatus(guards, GUARD);
        fillStatus(walls, WALL);
        
        int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        int unProtectNum = 0;
        
        for (auto point : guards) {
            int row = point.front();
            int col = point.back();
            
            for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); i++) {
                int x = row + dir[i][0];
                int y = col + dir[i][1];
                
                while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != GUARD && grid[x][y] != WALL) {
                    grid[x][y] = PROTECT;
                    x += dir[i][0];
                    y += dir[i][1];
                }
            }
        }
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    ++unProtectNum;
                }
            }
        }
        return unProtectNum;
        
    }
}; 



/* Official Solution 1 */
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n));   // 网格状态数组
        queue<tuple<int, int, int>> q;   // 广度优先搜索队列
        // 每个方向的单位向量
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (const auto& guard: guards) {
            grid[guard[0]][guard[1]] = -1;
            for (int k = 0; k < 4; ++k) {
                // 将四个方向视线对应的状态均添加进搜索队列中
                q.emplace(guard[0], guard[1], k);
            }
        }
        for (const auto& wall: walls) {
            grid[wall[0]][wall[1]] = -2;
        }
        while (!q.empty()) {
            auto [x, y, k] = q.front();
            q.pop();
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] >= 0) {
                // 沿着视线方向的下一个坐标合法，且不为警卫或墙
                if ((grid[nx][ny] & (1 << k)) == 0) {
                    // 对应状态未遍历过
                    grid[nx][ny] |= (1 << k);
                    q.emplace(nx, ny, k);
                }
            }
        }
        int res = 0;   // 未被保护格子数目
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++res;
                }
            }
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
    // 左右上下
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector guarded(m, vector<int8_t>(n));

        // 标记警卫格子、墙格子
        for (auto& g : guards) {
            guarded[g[0]][g[1]] = -1;
        }
        for (auto& w : walls) {
            guarded[w[0]][w[1]] = -1;
        }

        // 遍历警卫
        for (auto& g : guards) {
            // 遍历视线方向（左右上下）
            for (auto& [dx, dy] : DIRS) {
                // 视线所及之处，被保卫
                int x = g[0] + dx, y = g[1] + dy;
                while (0 <= x && x < m && 0 <= y && y < n && guarded[x][y] != -1) {
                    guarded[x][y] = 1; // 被保卫
                    x += dx;
                    y += dy;
                }
            }
        }

        // 统计没被保卫（值为 0）的格子数
        int ans = 0;
        for (auto& row : guarded) {
            ans += ranges::count(row, 0);
        }
        return ans;
    }
};
