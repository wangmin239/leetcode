/* Original Solution 1 */
class Solution {
public:
    typedef enum {
        LEFT2RIGHT = 1,
        UP2DOWN = 2,
        LEFT2DOWN = 3,
        RIGHT2DOWN = 4,
        LEFT2UP = 5,
        RIGHT2UP = 6,
        MAX
    } Dir;

    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        auto dfs = [&](int x, int y, auto&& self) {
            if (x == rows - 1 && y == cols - 1) {
                return true;
            }

            Dir toward = static_cast<Dir>(grid[x][y]);
            bool ans = false;

            visited[x][y] = true;
            switch(toward) {
                case LEFT2RIGHT:
                    if (y + 1 < cols && visited[x][y +1] == false && (grid[x][y + 1] & 1)) {
                        ans = self(x, y + 1, self);
                    }

                    if (y >= 1 && visited[x][y - 1] == false && (grid[x][y - 1] == LEFT2RIGHT || grid[x][y - 1] == RIGHT2DOWN || grid[x][y - 1] == RIGHT2UP)) {
                        ans |= self(x, y - 1, self);
                    }
                    return  ans;
                case UP2DOWN:
                    if (x + 1 < rows && visited[x + 1][y] == false && (grid[x + 1][y] == UP2DOWN || grid[x + 1][y] == LEFT2UP || grid[x + 1][y] == RIGHT2UP)) {
                        ans = self(x + 1, y, self);
                    }

                    if (x >= 1 && visited[x - 1][y] == false && (grid[x - 1][y] == UP2DOWN || grid[x - 1][y] == LEFT2DOWN || grid[x - 1][y] == RIGHT2DOWN)) {
                        ans |= self(x - 1, y, self);
                    }
                    return ans;
                case LEFT2DOWN:
                    if (x + 1 <= rows && visited[x + 1][y] == false && (grid[x + 1][y] == UP2DOWN || grid[x + 1][y] == LEFT2UP || grid[x + 1][y] == RIGHT2UP)) {
                        ans = self(x + 1, y, self);
                    }
                    if (y >= 1 && visited[x][y - 1] == false && (grid[x][y - 1] == LEFT2RIGHT || grid[x][y - 1] == RIGHT2DOWN || grid[x][y - 1] == RIGHT2UP)) {
                        ans |= self(x, y - 1, self);
                    }
                    return ans;
                case RIGHT2DOWN:
                    if (y + 1 < cols && visited[x][y + 1] == false && (grid[x][y + 1] == LEFT2RIGHT || grid[x][y + 1] == LEFT2DOWN || grid[x][y + 1] == LEFT2UP)) {
                        ans = self(x, y + 1, self);
                    }
                    if (x + 1 < rows && visited[x + 1][y] == false && (grid[x + 1][y] == UP2DOWN || grid[x + 1][y] == LEFT2UP || grid[x + 1][y] == RIGHT2UP)) {
                        ans |= self(x + 1, y, self);
                    }
                    return ans;
                case LEFT2UP:
                    if (x >= 1 && visited[x - 1][y] == false && (grid[x - 1][y] == UP2DOWN || grid[x - 1][y] == LEFT2DOWN || grid[x - 1][y] == RIGHT2DOWN)) {
                        ans = self(x - 1, y, self);
                    }
                    if (y >= 1 && visited[x][y - 1] == false && (grid[x][y - 1] == LEFT2RIGHT || grid[x][y - 1] == RIGHT2DOWN || grid[x][y - 1] == RIGHT2UP)) {
                        ans |= self(x, y - 1, self);
                    }
                    return ans;
                case RIGHT2UP:
                    if (y + 1 < cols && visited[x][y + 1] == false && (grid[x][y + 1] == LEFT2RIGHT || grid[x][y + 1] == LEFT2DOWN || grid[x][y + 1] == LEFT2UP)) {
                        ans = self(x, y + 1, self);
                    }
                    if (x >= 1 && visited[x -1][y] == false && (grid[x - 1][y] == UP2DOWN || grid[x - 1][y] == LEFT2DOWN || grid[x - 1][y] == RIGHT2DOWN)) {
                        ans |= self(x - 1, y, self);
                    }
                    return ans;
                default:
                    return false;
            }

        };
        return dfs(0, 0, dfs);
    }
};


/* Official Solution 1 */
class Solution {
public:
    static constexpr int MAX_N = 300 * 300 + 5;
    static constexpr int patterns[7] = {0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011};
    static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    struct DisjointSet {
        int f[MAX_N];
        
        DisjointSet() {
            for (int i = 0; i < MAX_N; ++i) f[i] = i;
        }
        
        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }
        
        void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    } ds;
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        auto getId = [&] (int x, int y) {
            return x * n + y;
        };

        auto handler = [&] (int x, int y) {
            int pattern = patterns[grid[x][y]];
            for (int i = 0; i < 4; ++i) {
                if (pattern & (1 << i)) {
                    int sx = x + dirs[i][0];
                    int sy = y + dirs[i][1];
                    if (sx >= 0 && sx < m && sy >= 0 && sy < n and (patterns[grid[sx][sy]] & (1 << ((i + 2) % 4)))) {
                        ds.merge(getId(x, y), getId(sx, sy));
                    }
                }
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};


/* Official Solution 2 */
class Solution {
public:
    static constexpr int MAX_N = 300 * 300 + 5;

    struct DisjointSet {
        int f[MAX_N];
        
        DisjointSet() {
            for (int i = 0; i < MAX_N; ++i) {
                f[i] = i;
            }
        }
        
        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }
        
        void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    } ds;
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        auto getId = [&] (int x, int y) {
            return x * n + y;
        };

        auto detectL = [&] (int x, int y) {
            if (y - 1 >= 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 || grid[x][y - 1] == 1)) {
                ds.merge(getId(x, y), getId(x, y - 1));
            }
        };

        auto detectR = [&] (int x, int y) {
            if (y + 1 < n && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 || grid[x][y + 1] == 1)) {
                ds.merge(getId(x, y), getId(x, y + 1));
            }
        };

        auto detectU = [&] (int x, int y) {
            if (x - 1 >= 0 && (grid[x - 1][y] == 3 || grid[x - 1][y] == 4 || grid[x - 1][y] == 2)) {
                ds.merge(getId(x, y), getId(x - 1, y));
            }
        };

        auto detectD = [&] (int x, int y) {
            if (x + 1 < m && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2)) {
                ds.merge(getId(x, y), getId(x + 1, y));
            }
        };
        
        auto handler = [&] (int x, int y) {
            switch (grid[x][y]) {
                case 1: {
                    detectL(x, y); detectR(x, y);
                } break;
                case 2: {
                    detectU(x, y); detectD(x, y);
                } break;
                case 3: {
                    detectL(x, y); detectD(x, y);
                } break;
                case 4: {
                    detectR(x, y); detectD(x, y);
                } break;
                case 5: {
                    detectL(x, y); detectU(x, y);
                } break;
                case 6: {
                    detectR(x, y); detectU(x, y);
                }
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};


/* Official Solution 3 */
class Solution {
    static constexpr int DIRS[7][2][2] = {
        {},
        {{0, -1}, {0, 1}},  // 站在街道 1，可以往左或者往右
        {{-1, 0}, {1, 0}},  // 站在街道 2，可以往上或者往下
        {{0, -1}, {1, 0}},  // 站在街道 3，可以往左或者往下
        {{0, 1}, {1, 0}},   // 站在街道 4，可以往右或者往下
        {{0, -1}, {-1, 0}}, // 站在街道 5，可以往左或者往上
        {{0, 1}, {-1, 0}},  // 站在街道 6，可以往右或者往上
    };

    // 判断街道 street 是否包含移动方向 (dx, dy)
    bool contains(int street, int dx, int dy) {
        auto& ds = DIRS[street];
        return ds[0][0] == dx && ds[0][1] == dy ||
               ds[1][0] == dx && ds[1][1] == dy;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector vis(m, vector<int8_t>(n));

        auto dfs = [&](this auto&& dfs, int x, int y) -> bool {
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            vis[x][y] = true; // 标记 (x, y) 访问过，从而避免重复访问
            for (auto& [dx, dy] : DIRS[grid[x][y]]) { // 枚举下一步往哪走
                int i = x + dx, j = y + dy;
                if (0 <= i && i < m && 0 <= j && j < n && !vis[i][j] &&
                    contains(grid[i][j], -dx, -dy) && dfs(i, j)) {
                    return true;
                }
            }
            return false;
        };

        return dfs(0, 0);
    }
};
