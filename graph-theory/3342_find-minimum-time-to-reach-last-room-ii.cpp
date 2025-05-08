/* Original Solution */
class Solution {
    class State {
        public:
            int x, y, dist, step;
            State(int _x, int _y, int _dist, int _step): x(_x), y(_y), dist(_dist), step(_step) {}
            bool operator < (const State &rhs) const {
                return dist > rhs.dist;
            }
    };
    
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime.front().size();
        vector<vector<int>> d(rows, vector<int>(cols, INT_MAX));
        vector<vector<int>> v(rows, vector<int>(cols, 0));
        priority_queue<State> q;
        int directions[][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        
        
        d[0][0] = 0;
        q.emplace(0, 0, 0, 0);
        
        while (q.empty() == false) {
            auto [x, y, dist, step] = q.top();
            q.pop();
            
            if (v[x][y]) {
                continue;
            }
            
            if (x == rows && y == cols) {
                break;
            }
            v[x][y] = 1;
            
            for (int i = 0; i < sizeof(directions) / sizeof(directions[0]); i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) {
                    continue;
                }
                
                int nDist = max(d[x][y], moveTime[nx][ny]) + step % 2 + 1;
                if (d[nx][ny] > nDist) {
                    d[nx][ny] = nDist;
                    q.emplace(nx, ny, nDist, step + 1);
                }
            }
        }
        return d[rows - 1][cols - 1];
    }
};


/* Official Solution */
class Solution {
    struct State {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
        bool operator < (const State &rth) const {
            return dis > rth.dis;
        } 
    };
public:
    const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;
        priority_queue<State> q;
        q.emplace(0, 0, 0);

        while (q.size()) {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y]) {
                continue;
            }
            if (s.x == n - 1 && s.y == m - 1) {
                break;
            }
            v[s.x][s.y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y) % 2 + 1;
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.emplace(nx, ny, dist);
                }
            }
        }
        return d[n - 1][m - 1];
    }
};
