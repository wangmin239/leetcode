/* Official Solution 1 */
class Solution {
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector id(m, vector<int>(n));
        int sx, sy, cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = 1 << cnt++;
                }
            }
        }

        vector bestEnergy(m, vector(n, vector<int>(1 << cnt, -1)));
        bestEnergy[sx][sy][0] = energy;
        struct Info {
            int x, y, mask, e, steps;
        };
        queue<Info> q;
        q.push({sx, sy, 0, energy, 0});
        while (!q.empty()) {
            Info t = q.front();
            q.pop();
            if (t.mask == (1 << cnt) - 1) {
                return t.steps;
            }
            if (t.e == 0) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = t.x + dx[i];
                int ny = t.y + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X') {
                    continue;
                }

                int ne = classroom[nx][ny] == 'R' ? energy : t.e - 1;
                int nmask = t.mask | id[nx][ny];

                if (ne > bestEnergy[nx][ny][nmask]) {
                    bestEnergy[nx][ny][nmask] = ne;
                    q.push({nx, ny, nmask, ne, t.steps + 1});
                }
            }
        }
        return -1;
    }
};


/* Official Solution 2 */
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector idx(m, vector<int>(n));
        int cnt_l = 0, sx = 0, sy = 0;
        for (int i = 0; i < m; i++) {
            auto& row = classroom[i];
            for (int j = 0; j < n; j++) {
                char b = row[j];
                if (b == 'L') {
                    idx[i][j] = 1 << cnt_l++;
                } else if (b == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        int u = 1 << cnt_l;
        vector max_energy(m, vector(n, vector<int8_t>(u, -1)));
        max_energy[sx][sy][0] = energy;
        struct Node { int x, y, e, mask; };
        vector<Node> q = {{sx, sy, energy, 0}};

        for (int ans = 0; !q.empty(); ans++) {
            auto tmp = move(q); // move 后 q 为空
            for (auto& [x, y, e, mask] : tmp) {
                if (mask == u - 1) {
                    return ans;
                }
                if (e == 0) {
                    continue;
                }
                for (auto& [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && classroom[nx][ny] != 'X') {
                        int new_e = classroom[nx][ny] == 'R' ? energy : e - 1;
                        int new_mask = mask | idx[nx][ny];
                        if (new_e > max_energy[nx][ny][new_mask]) {
                            max_energy[nx][ny][new_mask] = new_e;
                            q.emplace_back(nx, ny, new_e, new_mask);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
