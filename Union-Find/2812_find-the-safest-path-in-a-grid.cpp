/* Official Solution 1 */
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }
        
        vector<vector<int>> dis(n, vector<int>(n, -1));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || dis[nx][ny] != -1) {
                    continue;
                }
                dis[nx][ny] = dis[cx][cy] + 1;
                q.emplace(nx, ny);
            }
        }

        vector<vector<bool>> visit(n, vector<bool>(n));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<>> pq;
        visit[0][0] = true;
        pq.emplace(dis[0][0], 0, 0);
        int maxSafenessFactor = min(dis[0][0], dis[n - 1][n - 1]);
        while (!pq.empty()) {
            auto [val, cx, cy] = pq.top();
            pq.pop();
            maxSafenessFactor = min(maxSafenessFactor, val);
            if (cx == n - 1 && cy == n - 1) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = cx + dirs[i][0];
                int ny = cy + dirs[i][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny]) {
                    continue;
                }
                visit[nx][ny] = true;
                pq.emplace(dis[nx][ny], nx, ny);
            }
        }

        return maxSafenessFactor;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }
        
        vector<vector<int>> dis(n, vector<int>(n, -1));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || dis[nx][ny] != -1) {
                    continue;
                }
                dis[nx][ny] = dis[cx][cy] + 1;
                q.emplace(nx, ny);
            }
        }

        auto check = [&](int limit) -> bool {
            vector<vector<bool>> visit(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.emplace(0, 0);
            visit[0][0] = true;

            while (!q.empty()) {
                auto [cx, cy] = q.front();
                q.pop();
                if (cx == n - 1 && cy == n - 1) {
                    return true;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dirs[i][0];
                    int ny = cy + dirs[i][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n || 
                        visit[nx][ny] || dis[nx][ny] < limit) {
                        continue;
                    }
                    q.emplace(nx, ny);
                    visit[nx][ny] = true;
                }
            }

            return false;
        };


        int lo = 0, hi = min(dis[0][0], dis[n - 1][n - 1]);
        int res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return res;

    }
};


/* Official Solution 3 */
class UnionFind {
public:
    UnionFind(int n) {
        parent =  vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool connect(int x, int y) {
        return find(x) == find(y);
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }
        
        vector<vector<int>> dis(n, vector<int>(n, -1));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        vector<tuple<int, int, int>> cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                    cells.emplace_back(i, j, 0);
                }
            }
        }

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || dis[nx][ny] != -1) {
                    continue;
                }
                dis[nx][ny] = dis[cx][cy] + 1;
                cells.emplace_back(nx, ny, dis[nx][ny]);
                q.emplace(nx, ny);
            }
        }

        UnionFind uf(n * n);
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        for (int i = cells.size() - 1; i >= 0; i--) {
            auto [cx, cy, dist] = cells[i];
            visit[cx][cy] = true;
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && visit[nx][ny]) {
                    uf.unite(cx * n + cy, nx * n + ny);
                }
            }
            if (uf.connect(0, n * n - 1)) {
                return dist;
            }
        }

        return 0;
    }
};
