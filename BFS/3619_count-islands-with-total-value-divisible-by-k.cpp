/* Original Solution 1 */
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        const int dirs = 4;
        const pair<int, int> dirArr[dirs] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int ans = 0;

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (grid[x][y] == 0) {
                    continue;
                }

                queue<pair<int, int>> posQue;

                posQue.push({x, y});


                int sum = grid[x][y] % k;
                int size = posQue.size();
                pair<int, int> curPos;
                int curX, curY, nx, ny;

                while (size--) {
                    curPos = posQue.front();
                    curX = curPos.first;
                    curY = curPos.second;

                    grid[curX][curY] = 0;
                    posQue.pop();

                    for (int i = 0; i < dirs; i++) {
                        nx = curX + dirArr[i].first;
                        ny = curY + dirArr[i].second;

                        if (nx < 0 || nx == rows || ny < 0 || ny == cols || grid[nx][ny] == 0) {
                            continue;
                        }
                        sum += grid[nx][ny];
                        sum %= k;
                        grid[nx][ny] = 0;
                        posQue.push({nx, ny});
                    }

                    size = posQue.size();
                }



                if (sum % k == 0) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};


/* Original Solution 1 */
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        const int dirs = 4;
        const pair<int, int> dirArr[dirs] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto dfs = [&](int x, int y,auto&& self) {
            if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == 0) {
                return 0;
            }

            int sum = grid[x][y];
            grid[x][y] = 0;

            for (int i = 0; i < dirs; i++) {
                int nx = x + dirArr[i].first;
                int ny = y + dirArr[i].second;
                sum += self(nx, ny, self);
                sum %= k;
            }

            return sum;
        };

        int cnt = 0;

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (grid[x][y] == 0) {
                    continue;
                }

                int sum = dfs(x, y, dfs);

                if (sum % k == 0) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int dirs[5] = {-1, 0, 1, 0, -1};

        auto dfs = [&](int i, int j, auto&& self) -> long long {
            long long sum = grid[i][j];
            grid[i][j] = 0;
            for (int d = 0; d < 4; ++d) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                    sum += self(x, y, self);
                }
            }
            return sum;
        };

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && dfs(i, j, dfs) % k == 0) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};


/* Official Solution 2 */
class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            long long res = grid[i][j];
            grid[i][j] = 0; // 标记为访问过
            for (auto [dx, dy] : DIRS) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < m && 0 <= y && y < n && grid[x][y]) {
                    res += dfs(x, y);
                }
            }
            return res;
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && dfs(i, j) % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
