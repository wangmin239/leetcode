/* Original Solution 1 
 *
 * Two test case failed. 689 / 691
 */
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid.front().size();
        int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        queue<tuple<int, int, int>> que;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        const int maxRows = 100;

        if (health <= grid[0][0]) {
            return false;
        }


        visited[0][0] = true;
        health -= grid[0][0];
        que.push({0, 0, health});

        while (que.empty() == false) {
            int size = que.size();
            unordered_map<int, int> maxHealth;

            while (size--) {
                auto [x, y, curHealth] = que.front();
                que.pop();

                if (x == rows - 1 && y == cols - 1) {
                    return true;
                }

                for (int i = 0; i < sizeof(dirs) /sizeof(dirs[0]); i++) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];

                    if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || visited[nx][ny] || curHealth <= grid[nx][ny]) {
                        continue;
                    }
                    int pos = nx * maxRows + ny;
                    maxHealth[pos] = max(maxHealth[pos], curHealth - grid[nx][ny]);
                }
            }

            for (auto [pos, nextHealth] : maxHealth) {
                int ny = pos % maxRows;
                int nx = (pos - ny) / maxRows;
                que.push({nx, ny, nextHealth});
                visited[nx][ny] = true;
            }

        }

        return false;
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty()) {
            auto [val, cx, cy] = pq.top(); 
            pq.pop();
            if (dis[cx][cy] >= 0) {
                continue;
            }
            dis[cx][cy] = val;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dirs[k][0];
                int ny = cy + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || dis[nx][ny] >= 0) {
                    continue;
                }
                pq.emplace(val + grid[nx][ny], nx, ny);
            }
        }

        return dis[m - 1][n - 1] < health;
    }
};



/* Official Solution 2 */
class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        
        deque<pair<int, int>> q;
        q.emplace_front(0, 0);
        dis[0][0] = grid[0][0];
        
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop_front();
            // 第一次出队时，保证是最短距离
            if (cx == m - 1 && cy == n - 1) {
                return true;
            }
            
            for (auto& [dx, dy] : DIRS) {
                int nx = cx + dx, ny = cy + dy;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                int cost = dis[cx][cy] + grid[nx][ny];
                // 剪枝：新距离不满足健康要求
                if (cost >= health) {
                    continue;
                }
                if (cost < dis[nx][ny]) {
                    dis[nx][ny] = cost;
                    if (grid[nx][ny] == 0) {
                        q.emplace_front(nx, ny);
                    } else {
                        q.emplace_back(nx, ny);
                    }
                }
            }
        }
        
        return false;
    }
};
