class Solution {
public:
    constexpr static int INF = 1e9;
    constexpr static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fireTime(m, vector<int>(n, INF));
        /* 通过 bfs 求出每个格子着火的时间 */
        bfs(grid, fireTime);
        /* 二分查找找到最大停留时间 */
        int ans = -1;
        int low = 0, high = m * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;     
            if (check(fireTime, grid, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans >= m * n ? 1e9 : ans;
    }

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &fireTime) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    fireTime[i][j] = 0;
                }
            }
        }

        int time = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (grid[nx][ny] == 2 || fireTime[nx][ny] != INF) {
                            continue;
                        }
                        q.emplace(nx, ny);
                        fireTime[nx][ny] = time;
                    }
                }
            }
            time++;
        }
    }

    bool check(vector<vector<int>> &fireTime, vector<vector<int>> &grid, int stayTime) {
        int m = fireTime.size();
        int n = fireTime[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, stayTime);
        visit[0][0] = true;

        while (!q.empty()) {
            auto [cx, cy, time] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cx + dirs[i][0];
                int ny = cy + dirs[i][1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (visit[nx][ny] || grid[nx][ny] == 2) {
                        continue;
                    }
                    /* 到达安全屋 */
                    if (nx == m - 1 && ny == n - 1) {
                        return fireTime[nx][ny] >= time + 1;
                    }
                    /* 火未到达当前位置 */
                    if (fireTime[nx][ny] > time + 1) {
                        q.emplace(nx, ny, time + 1);
                        visit[nx][ny] = true;
                    }
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    constexpr static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    constexpr static int INF = 1e9;
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fireTime(m, vector<int>(n, INF));
        /* 通过 bfs 求出每个格子着火的时间 */
        bfs(grid, fireTime);
        /* 找到起点到终点的最短时间 */
        int arriveTime = getArriveTime(grid, fireTime, 0);
        /* 安全屋不可达 */
        if (arriveTime < 0) {
            return -1;
        }
        /* 火不会到达安全屋 */
        if (fireTime[m - 1][n - 1] == INF) {
            return 1e9;
        }
        int ans = fireTime[m - 1][n - 1] - arriveTime;
        return getArriveTime(grid, fireTime, ans) >= 0 ? ans : (ans - 1);
    }    

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &fireTime) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    fireTime[i][j] = 0;
                }
            }
        }

        int time = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (grid[nx][ny] == 2 || fireTime[nx][ny] != INF) {
                            continue;
                        }
                        q.emplace(nx, ny);
                        fireTime[nx][ny] = time;
                    }
                }
            }
            time++;
        }
    }

    int getArriveTime(vector<vector<int>> &grid, vector<vector<int>> &fireTime, int stayTime) {
        int m = fireTime.size();
        int n = fireTime[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        q.emplace(0, 0, stayTime);
        visit[0][0] = true;
        while (!q.empty()) {
            auto [cx, cy, time] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (grid[nx][ny] == 2 || visit[nx][ny]) {
                        continue;
                    }
                    if (nx == m - 1 && ny == n - 1) {
                        return time + 1;
                    }
                    if (fireTime[nx][ny] > time + 1) {
                        visit[nx][ny] = true;
                        q.emplace(nx, ny, time + 1);
                    }
                }
            }
        }
        return -1;
    }
};


static int stream_off = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    static constexpr int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

    int maximumMinutes(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid.front().size(), visBit = 1;

        auto solve = [&](int ex, int ey) -> pair<int, int> {
            if (grid[ex][ey] == 2) return {0x3f3f3f3f, 0x3f3f3f3f};
            int people = 0x3f3f3f3f, fire = 0x3f3f3f3f;
            ++visBit;
            deque<pair<int, int>> q{{ex, ey}};
            grid[ex][ey] |= (1 << visBit);
            int sz, des = 0;
            while ((sz = q.size())) {
                ++des;
                while (sz--) {
                    auto [x, y] = q.front();
                    q.pop_front();
                    if (fire == 0x3f3f3f3f && grid[x][y] & 1) fire = des;
                    if (people == 0x3f3f3f3f && x == 0 && y == 0) people = des;
                    if (fire != 0x3f3f3f3f && people != 0x3f3f3f3f) return {people, fire};
                    for (auto [xx, yy]: dir) {
                        int nx = x + xx, ny = y + yy;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] & 2 || grid[nx][ny] >> visBit)
                            continue;
                        grid[nx][ny] |= 1 << visBit;
                        q.emplace_back(nx, ny);
                    }
                }
            }
            return {people, fire};
        };

        auto &&[pa, fa] = solve(m - 2, n - 1);
        auto &&[pb, fb] = solve(m - 1, n - 2);
        int mpeople = min(pa, pb), mfire = min(fa, fb);
        if (mpeople == 0x3f3f3f3f) return -1;
        if (mfire == 0x3f3f3f3f) return 1000000000;
        int ans = mfire - mpeople;
        if (max(fa - pa, fb - pb) == ans) --ans;
        if (ans < 0) return -1;
        return ans;
    }
};