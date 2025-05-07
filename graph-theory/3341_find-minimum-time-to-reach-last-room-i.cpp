class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime.front().size();
        int directions[][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

        dp[0][0] = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                for (int i = 0; i < sizeof(directions) / sizeof(directions[0]); i++) {
                    int x = row + directions[i][0];
                    int y = col + directions[i][1];
                    
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        if (moveTime[x][y] <= dp[row][col]) {
                            dp[x][y] = min(dp[x][y], dp[row][col] + 1);
                        } else {
                            dp[x][y] =  moveTime[x][y] + 1;
                        }
                    }
                }
            }
        }

        return dp[rows - 1][cols - 1];
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
        q.push(State(0, 0, 0));

        while (q.size()) {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y]) {
                continue;
            }
            v[s.x][s.y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));
                }
            }
        }
        return d[n - 1][m - 1];
    }
};
